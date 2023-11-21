# CMake Fundamental

## Difference between include_directories and target_include_directories

Both `include_directories()` and `target_include_directories()` in CMake are
used to specify include directories, but they have different scopes and use
cases. Let's go over their differences:

1. **Scope**:

   - `include_directories()`: This command adds include directories at the
     directory level. This means that every target defined in the current CMake
     directory and below (in terms of directory hierarchy) will inherit these
     include directories. It's a global approach, affecting all subsequent
     targets.
   - `target_include_directories()`: This command adds include directories at
     the target level. Only the specified target will be aware of these include
     directories. It allows for a more modular and granular approach.

2. **Usage**:

   - `include_directories()`:
     ```cmake
     include_directories(path/to/includes)
     ```
   - `target_include_directories()`:
     ```cmake
     target_include_directories(target_name PRIVATE|PUBLIC|INTERFACE path/to/includes)
     ```

3. **Modifiers (PRIVATE, PUBLIC, INTERFACE)**:

   - With `target_include_directories()`, you can specify how the include
     directories should be treated:
     - `PRIVATE`: The include directories are only used by the target itself.
     - `PUBLIC`: The include directories are used by the target and are also
       propagated to any other targets that link against this target.
     - `INTERFACE`: The include directories are not used by the target itself
       but are propagated to any other targets that link against this target.

4. **Best Practices**:
   - Modern CMake best practices recommend using `target_include_directories()`
     over `include_directories()`. This is because `target_include_directories()`
     provides a more precise way to manage dependencies, reducing the chances of
     potential conflicts and ensuring that targets only have access to the
     include directories they actually need.

In summary, while both commands are used to specify include directories,
`target_include_directories()` is more flexible and precise, allowing for
better control over dependencies. If you're starting a new project or updating
an existing one, it's generally recommended to use
`target_include_directories()`.
