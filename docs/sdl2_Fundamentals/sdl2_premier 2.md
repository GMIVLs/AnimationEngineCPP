# SDL2

## So, the sdl2 and the extension are for dynamic or static that i downloaded in the script above?

The SDL2 and its extensions you downloaded using the script are dynamic
libraries. When you use a package manager like Homebrew on macOS to install
libraries, it typically installs the dynamic versions of the libraries.

Dynamic libraries are preferred in most cases as they allow programs to share
code which is loaded into memory only once, thereby saving memory. They also
enable you to update the library separately from the application that uses it.

However, dynamic libraries do come with a caveat: the library version that the
application was linked against at compile time must be available at runtime as
well. If the library is updated to a version that is not backward-compatible,
applications that depend on it may break.

On the other hand, static libraries are incorporated into the application at
compile time. This makes the application self-contained and ensures it won't
break due to library updates, but it may lead to larger binary sizes and
duplication of library code in memory if multiple applications use the same
library.

In most cases, you will find both static and dynamic versions of a library
available for your use, and you can choose the one that best suits your
application's needs.
