set(KIT ${PROJECT_NAME})

#
# Tests
#
set(TEST_SOURCES
  ctkVTKConnectionTest1.cpp
  ctkVTKObjectTest1.cpp
  )

#
# Tests expecting CTKData to be set
#
if(EXISTS "${CTKData_DIR}")
  list(APPEND TEST_SOURCES
    vtkLightBoxRendererManagerTest1.cpp
    )
endif()

#
# Pre-requisites
#

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
 )

#
# Test helpers
#

set(KIT_HELPER_SRCS
  ctkVTKObjectTestHelper.cpp
  )

if(CTK_QT_VERSION VERSION_GREATER "4")
  QT5_WRAP_CPP(KIT_HELPER_SRCS ctkVTKObjectTestHelper.h)
else()
  QT4_WRAP_CPP(KIT_HELPER_SRCS ctkVTKObjectTestHelper.h)
endif()

#
# Tests
#

create_test_sourcelist(Tests ${KIT}CppTests.cpp
  ${TEST_SOURCES}
  #EXTRA_INCLUDE TestingMacros.h
  )

SET (TestsToRun ${Tests})
REMOVE (TestsToRun ${KIT}CppTests.cpp)

set(LIBRARY_NAME ${PROJECT_NAME})

add_executable(${KIT}CppTests ${Tests} ${KIT_HELPER_SRCS})
target_link_libraries(${KIT}CppTests ${LIBRARY_NAME} ${CTK_BASE_LIBRARIES})

#
# Add Tests
#

SIMPLE_TEST( ctkVTKConnectionTest1 )
SIMPLE_TEST( ctkVTKObjectTest1 )

#
# Add Tests expecting CTKData to be set
#
if(EXISTS "${CTKData_DIR}")
  set(baseline_relative_location "Libs/Visualization/VTK/Core")
  SIMPLE_TEST_WITH_DATA( vtkLightBoxRendererManagerTest1 ${baseline_relative_location}/vtkLightBoxRendererManagerTest1.png)
endif()

