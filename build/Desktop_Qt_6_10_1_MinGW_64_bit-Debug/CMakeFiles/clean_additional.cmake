# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PostApocalypseAlarmClock_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PostApocalypseAlarmClock_autogen.dir\\ParseCache.txt"
  "PostApocalypseAlarmClock_autogen"
  )
endif()
