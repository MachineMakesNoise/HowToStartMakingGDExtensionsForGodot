# Setup requirement for this build file.
CMAKE_MINIMUM_REQUIRED(VERSION 3.24 FATAL_ERROR)
# Setup project name.
PROJECT(HowToStartMakingGDExtensionsForGodot)
# Add godot-cpp as part of this multi-project build.
ADD_SUBDIRECTORY(external/godot-cpp)
# Add the extension as part of this multi-project build.
ADD_SUBDIRECTORY(gdextension_test)