#include "dialog.h"
#include "ui_dialog.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardPaths>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);

    // Manually connect the button to your function
    connect(ui->SubmitButton, &QPushButton::clicked, this, &Dialog::on_SubmitButton_clicked);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_SubmitButton_clicked()
{
    QJsonObject newAlarm;
    newAlarm["name"] = ui->AlarmName->text().isEmpty() ? "New Alarm" : ui->AlarmName->text();
    newAlarm["hour"] = ui->Hours->value();
    newAlarm["minute"] = ui->Minutes->value();

    // 2. Map your specific checkbox names to a JSON array
    QJsonArray daysArray;
    daysArray.append(ui->MonCheck->isChecked());
    daysArray.append(ui->TueCheck->isChecked());
    daysArray.append(ui->WedCheck->isChecked());
    daysArray.append(ui->ThuCheck->isChecked());
    daysArray.append(ui->FriCheck->isChecked());
    daysArray.append(ui->SatCheck->isChecked());
    daysArray.append(ui->SunCheck->isChecked());
    newAlarm["repeatDays"] = daysArray;

    // 3. Persistent Storage (Load existing list, add new, then save)
    QString filePath = "alarms.json";
    QFile file(filePath);
    QJsonArray alarmList;

    // Read existing data if the file exists
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument loadDoc = QJsonDocument::fromJson(file.readAll());
        alarmList = loadDoc.array();
        file.close();
    }

    // Add our new alarm to the list
    alarmList.append(newAlarm);

    // Save the updated list back to the file
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument saveDoc(alarmList);
        file.write(saveDoc.toJson());
        file.close();
    }

    accept();
}

