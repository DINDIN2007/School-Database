# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\School_Database_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\School_Database_autogen.dir\\ParseCache.txt"
  "School_Database_autogen"
  )
endif()
