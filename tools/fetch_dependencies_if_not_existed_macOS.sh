#!/usr/bin/env bash
echo "
                █▀ █▀▄ █░░ ▀█ ░ █▀█   █▀▄ █▀█ █░█░█ █▄░█ █░░ █▀█ ▄▀█ █▀▄ █▀▀ █▀█
                ▄█ █▄▀ █▄▄ █▄ ▄ █▄█   █▄▀ █▄█ ▀▄▀▄▀ █░▀█ █▄▄ █▄█ █▀█ █▄▀ ██▄ █▀▄
"
# Install Homebrew if it's not installed.
if ! command -v brew &>/dev/null; then
    echo "Homebrew could not be found. Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

# Get the Homebrew install directory
brew_prefix=$(brew --prefix)

# Create the dependencies directory
mkdir -p dependencies
cd dependencies

# Install the SDL2 library and its extensions
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
brew install sdl2_gfx

# Symlink the libraries into their respective directories
for library in sdl2 sdl2_image sdl2_ttf sdl2_gfx; do
    # Directories to be created
    directories=("$library/lib" "$library/include")

    # Paths to the files for symlinking
    files=("$brew_prefix/Cellar/$library/*/lib/*.dylib" "$brew_prefix/Cellar/$library/*/include/*")

    # Initialize flag to check if all files are already installed
    all_files_installed=true

    # Iterate over each directory and file in parallel
    for i in ${!directories[*]}; do
        directory=${directories[$i]}
        file_path=${files[$i]}

        # Check if directory exists, if not create it
        if [ ! -d "$directory" ]; then
            mkdir -p "$directory"
        fi

        # Check each file in the file_path
        for file in $file_path; do
            # If symlink doesn't exist, create it
            if [ ! -e "$directory/$(basename $file)" ]; then
                ln -s $file "$directory"
                # Set the flag to false if a new file is installed
                all_files_installed=false
            fi
        done
    done

    # If all files were already installed, print a message
    if $all_files_installed; then
        echo "All files for $library are already installed."
    fi
done

# # Symlink the libraries into their respective directories
# for library in sdl2 sdl2_image sdl2_ttf sdl2_gfx; do
#   mkdir -p $library/lib
#   mkdir -p $library/include
#   ln -s $brew_prefix/Cellar/$library/*/lib/*.dylib $library/lib
#   ln -s $brew_prefix/Cellar/$library/*/include/* $library/include
# done

cd ..

echo "SDL2 and extensions have been downloaded and built in the dependencies directory."
