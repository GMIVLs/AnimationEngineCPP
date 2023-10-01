##################################################
#                                                #
#      █▀▄▀█ ▄▀█ █▄▀ █▀▀   █▀▀ █ █░░ █▀▀         #
#      █░▀░█ █▀█ █░█ ██▄   █▀░ █ █▄▄ ██▄         #
#                                                #
##################################################
# Variables
BINARY_NAME=main
NUMBER_CORES=8
SDL2_DIR = $(HOMEBREW_DIR)/sdl2/2.28.3
SDL2_IMAGE_DIR = $(HOMEBREW_DIR)/sdl2_image/2.6.3_2
SOURCES = src/main.cpp src/lib/veclib/vector2d.cpp
OUTPUT = build/debug/main

# Phony target since 'runcli' isn't a file
.PHONY: all debug release run


all: debug

debug: link_compile_commands
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build/debug
	$(MAKE) -j $(NUMBER_CORES) -C build/debug
	./build/debug/$(BINARY_NAME)

release: link_compile_commands
	cmake -DCMAKE_BUILD_TYPE=Release -S . -B build/release
	$(MAKE) -j $(NUMBER_CORES) build/release
	./build/debug/$(BINARY_NAME)

# For the clangd language server integration
link_compile_commands:
	if [ -L compile_commands.json ]; then \
		rm -f compile_commands.json; \
	fi
	ln -s build/debug/compile_commands.json compile_commands.json

run: $(OUTPUT)
	./$(OUTPUT)
	@$(MAKE) link_compile_commands

$(OUTPUT): $(SOURCES)
	clang++ -std=c++17 \
	-I$(SDL2_DIR)/include/SDL2/ \
	-I$(SDL2_IMAGE_DIR)/include/SDL2/ \
	-L$(SDL2_DIR)/lib -lSDL2 \
	-L$(SDL2_IMAGE_DIR)/lib -lSDL2_image \
	-o $@ $(SOURCES)

fetch_sdl2.0_dependencies:
	@echo "Running now script to fetch dependencies and link them in the dependencies directory ..."
	chmod +x $(PROJECT_DIR)/tools/fetch_dependencies_if_not_existed_macOS.sh
	$(PROJECT_DIR)/tools/fetch_dependencies_if_not_existed_macOS.sh


help:
	@echo "\033[35m ********************************************************\033[0m"
	@echo ""
	@echo "\033[31m      ░█▀▀█ █▀▀▄ ░▀░ █▀▄▀█ █▀▀█ ▀▀█▀▀ ░▀░ █▀▀█ █▀▀▄ 　\033[0m"
	@echo "\033[31m      ▒█▄▄█ █░░█ ▀█▀ █░▀░█ █▄▄█ ░░█░░ ▀█▀ █░░█ █░░█ 　\033[0m"
	@echo "\033[31m      ▒█░▒█ ▀░░▀ ▀▀▀ ▀░░░▀ ▀░░▀ ░░▀░░ ▀▀▀ ▀▀▀▀ ▀░░▀ 　\033[0m"
	@echo "\033[31m               ▒█▀▀▀ █▀▀▄ █▀▀▀ ░▀░ █▀▀▄ █▀▀           \033[0m"
	@echo "\033[31m               ▒█▀▀▀ █░░█ █░▀█ ▀█▀ █░░█ █▀▀           \033[0m"
	@echo "\033[31m               ▒█▄▄▄ ▀░░▀ ▀▀▀▀ ▀▀▀ ▀░░▀ ▀▀▀           \033[0m"
	@echo ""
	@echo "\033[35m ********************************************************\033[0m"
	@echo "Available commands:"
	@echo "\033[32m   make all                       \033[0m   - equivalent to make debug"
	@echo "\033[32m   make debug                     \033[0m   - build the project in Debug mode"
	@echo "\033[32m   make release                   \033[0m   - build the project in Release mode"
	@echo "\033[32m   make run                       \033[0m   - build and run the project using Clang compiler"
	@echo "\033[32m   make fetch_sdl2.0_dependencies \033[0m   - install all the SDL2 dependencies including gfx, font, image"
	@echo "\033[32m   make help                      \033[0m   - show this help message"
	@echo "\033[35m ********************************************************\033[0m"
