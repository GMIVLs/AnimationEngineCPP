# Make Fundamental

## Make flags - most common

- When using make, the -j 8 flag specifies that up to 8 jobs (or commands) should
  be run simultaneously, which can speed up the build process on multi-core
  systems. In addition to the -j flag, there are several other flags and options
  that can be useful depending on your needs:

```sh
-k or --keep-going: Continue as much as possible after encountering an error. This can be useful when you want to see all the errors in one go, rather than fixing one at a time.
-C <dir> or --directory=<dir>: Change to the directory <dir> before reading the makefiles.
-f <file> or --file=<file>: Use <file> as the makefile. This can be useful if your makefile has a non-standard name.
-n or --just-print: Print the commands that would be executed, but do not actually execute them. This is useful for debugging makefiles.
-s or --silent: Do not print the commands as they are executed (silent mode).
-B or --always-make: Unconditionally make all targets, regardless of whether they appear to be up-to-date.
-i or --ignore-errors: Continue to build other targets even if a command encounters an error.
-q or --question: Do not run any commands or print anything; just return an exit status that indicates whether the specified targets are already up-to-date.
-w or --print-directory: Print a message indicating the current directory before and after other processing. This can be useful when recursive invocations of make are used.
-o <file> or --old-file=<file>: Consider <file> as very old and don't remake it unless its dependencies are newer than it.
-I <dir> or --include-dir=<dir>: Specifies a directory to search for included makefiles.
--no-builtin-rules: Disable all built-in implicit rules.
--warn-undefined-variables: Warn when an undefined variable is referenced.
```
