######################################
#      BUILD FOR TESTING MODULE
######################################

if(BUILD_TESTS)

    ## vcpkg libraries - Logging header
    # Required by vckpge
    find_package(glog CONFIG REQUIRED)
    ######################################
    # definition,
    ######################################
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    # This will read all the files inside our tests module
    file(GLOB_RECURSE SOURCES ./*.cpp            # For define all curernt tests/*.cpp
                              ../src/lib/*.cpp   # For define all the source files excpet main.cpp
    )
    # Remove main.cpp from the list
    # list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp") # Not Working!!
    add_executable(my_test ${SOURCES}) # ../src/lib/veclib/lib/vector2d.cpp ../src/lib/veclib/lib/vect.cpp


  # Link headers
  target_include_directories(
    my_test PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/include/SDL2
                 ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/include/SDL2
            glog::glog
            GTest::gtest_main
    )

  target_link_libraries(
    my_test
    PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/libSDL2.dylib
            ${CMAKE_SOURCE_DIR}/dependencies/sdl2_image/lib/libSDL2_image.dylib
            glog::glog
            GTest::gtest_main
    )
    include(GoogleTest)
    gtest_discover_tests(my_test)

    # --------------------------------------------------------------------
    #                  Define A Build Type (Test)
    # --------------------------------------------------------------------
    set(CMAKE_BUILD_TYPE Test CACHE STRING "Set the build type to Test" FORCE)
    # Define flags for Test build
    set(CMAKE_CXX_FLAGS_TEST "${CMAKE_CXX_FLAGS_TEST} -Wall -Wextra -g")
    set(CMAKE_C_FLAGS_TEST "${CMAKE_C_FLAGS_TEST} -Wall -Wextra -g")
    # Check if we are using the Test build
    if(CMAKE_BUILD_TYPE STREQUAL "Test")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_TEST}")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_TEST}")
    endif()


endif()
