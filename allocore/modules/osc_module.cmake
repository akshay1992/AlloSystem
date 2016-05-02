set(BUILD_OSC 1)


if(BUILD_OSC)
message(STATUS "Building OSC module.")

set(OSC_HEADERS
    allocore/protocol/al_OSC.hpp
    allocore/system/al_Parameter.hpp
	allocore/system/al_Preset.hpp
	allocore/io/al_HtmlParameterServer.hpp
)

# for oscpack (oscpack sources are included with AlloSystem)
include(TestBigEndian)
test_big_endian(TEST_ENDIAN)
if (TEST_ENDIAN MATCHES 0)
  add_definitions(-DOSC_HOST_LITTLE_ENDIAN)
else()
  add_definitions(-DOSC_HOST_BIG_ENDIAN)
endif()

set(OSCPACK_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/")

list(APPEND ALLOCORE_SRC
  ${OSCPACK_ROOT_DIR}/oscpack/osc/OscOutboundPacketStream.cpp
  ${OSCPACK_ROOT_DIR}/oscpack/osc/OscPrintReceivedElements.cpp
  ${OSCPACK_ROOT_DIR}/oscpack/osc/OscReceivedElements.cpp
  ${OSCPACK_ROOT_DIR}/oscpack/osc/OscTypes.cpp
  src/protocol/al_OSC.cpp
  src/system/al_Parameter.cpp
  src/system/al_Preset.cpp
  src/io/al_HtmlParameterServer.cpp
  )

INCLUDE_DIRECTORIES("${OSCPACK_ROOT_DIR}")

list(APPEND ALLOCORE_HEADERS ${OSC_HEADERS})

#list(APPEND ALLOCORE_DEP_INCLUDE_DIRS
#  ${GLUT_INCLUDE_DIR})

#list(APPEND ALLOCORE_LINK_LIBRARIES
#  ${GLUT_LIBRARY})

else()
    message("NOT Building OSC module.")
    foreach(header ${OSC_HEADERS})
        list(APPEND OSC_DUMMY_HEADER_INFO "${header}::::OSC")
    endforeach()
    list(APPEND ALLOCORE_DUMMY_HEADERS ${OSC_DUMMY_HEADER_INFO})

endif(BUILD_OSC)
