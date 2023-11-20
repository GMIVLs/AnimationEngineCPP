# GOOGLETEST AS GIt SUBMODULE

## CONFIG

Here, we will allow the `git` to include the `googletest` as a submodule by
its own, and will be installed directly using CMakeLists.txt

## SETUP AND PREPARATION

1. Get the `googletest` from github using the `submodule`

- Inside the `dependencies` directory.

```sh
git submodule add git@github.com:google/googletest.git
```

- You can get the inforamtion of the `googletest` using:

```sh
git submodule
```

- You can also update the `googletest` submodule easily using:

```git
git submodule update --init --recursive
```

2. We can automate this easily using the `cmake`, by adding the following
   script to the `dependencies/CMakeLists.txt`

- Create a directory `cmake` at the root directory of your project, then add a
  `cmake/CMakeLists.txt` file from our `project` root directory.

  - Should include the following script, which will read only the submodules
    and update them in your dependencies file.
  - You can see a `.gitmodule` located at the root directory that includes the
    `googletest` as a submodle

    ```sh
       [submodule "dependencies/googletest"]
           path = dependencies/googletest
           url = https://github.com/google/googletest.git
    ```

  - The automation script below, will only execute the submodles based on the
    `.gitmodule`, and it will maintain and update the submodules (e.g.,
    googletest).
  - **NOTE**: we will continue on push to our repository without excluding the
    `googletest`, because it becomes a `submodule`, means it will be shown as a
    link in our github repository

```sh
# Adapted from https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html
# This will recursively download and update the submodules that you ahve in the dependencies.
# All submodules should be included there using (git submodule add <repo_name> dependencies/repo_name)
find_package(Git QUIET)
if(GIT_FOUND)
    option(UPDATE_SUBMODULES "Check submodules during build" ON)
    if(NOT UPDATE_SUBMODULES)
        return()
    endif()
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    OUTPUT_VARIABLE EXISTING_SUBMODULES
                    RESULT_VARIABLE RETURN_CODE
                    OUTPUT_STRIP_TRAILING_WHITESPACE)
    message(STATUS "Updating git submodules:\n${EXISTING_SUBMODULES}")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE RETURN_CODE)
    if(NOT RETURN_CODE EQUAL "0")
        message(WARNING "Cannot update submodules. Git command failed with ${RETURN_CODE}")
        return()
    endif()
    message(STATUS "Git submodules updated successfully")
endif()
```

- Include it in your `root` `CmakeLists.txt` file (located at the root of the project)
  - It should come first as it will include the dependencies based on the `git submodule`

```sh
include(cmake/UpdateSubmodules.cmake)

```

3. Now, the `make` commands will work normall and keep on update all the
   submodules that we have in our dependencies directory and based on the
   `.gitmodule`.

## NOTES

1. You should not delete the `submodules` from your ./dependencies directory,
   as they will not be included in your remote GitHub repository, and their
   sized is preseerved to their origin location, (all what we do is link to the
   location of these submodule dependencies, e.g.,`googletest`).
