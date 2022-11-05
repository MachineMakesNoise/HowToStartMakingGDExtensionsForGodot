# Setup requirement for this build file.
cmake_minimum_required(VERSION 3.24 FATAL_ERROR)
# Setup project name.
project(HowToStartMakingGDExtensionsForGodot)
# Add godot-cpp as part of this multi-project build.
add_subdirectory(external/godot-cpp)
# Add the extension as part of this multi-project build.
add_subdirectory(gdextension_test)