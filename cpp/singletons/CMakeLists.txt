#--------------------------------------------------------
# The CMakeLists.txt for:                MOOSSimInterface
# Author(s):                                          JNW
#--------------------------------------------------------
project(MOOSSimInterface)

FILE(GLOB SRC *.cpp
)

FILE(GLOB RESOURCES *.h
)

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC} ${RESOURCES})

if (COMPILEMOOS10)
  TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  BaseTask
  MOOS
  m
  mbutil
  pthread
  ExtendedBridge
  protoc
  protobuf
  HWInterface)
else (COMPILEMOOS10)
  TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  BaseTask
  MOOS
  MOOSGen
  m
  MOOSUtility
  mbutil
  pthread
  ExtendedBridge
  protoc
  protobuf
  HWInterface)
endif (COMPILEMOOS10)


