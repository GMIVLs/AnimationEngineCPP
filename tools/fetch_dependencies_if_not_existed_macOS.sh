#!/usr/bin/env bash

# Install Homebrew if it's not installed.
if ! command -v brew &> /dev/null
then
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
  mkdir -p $library/lib
  mkdir -p $library/include
  ln -s $brew_prefix/Cellar/$library/*/lib/*.dylib $library/lib
  ln -s $brew_prefix/Cellar/$library/*/include/* $library/include
done

cd ..

echo "SDL2 and extensions have been downloaded and built in the dependencies directory."

