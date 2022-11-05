REM Invoke CMake to create project files. Instruct it to use specific Visual Studio "kit", x64 platform and Debug build type.
cmake . -Bbuild -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Debug
REM Invoke CMake to actually build the project.
cmake --build ./build
REM Invoke CMake to install the project. Instruct it to use Debug configuration and nested folder as "prefix" for the installation.
cmake --install ./build --config Debug --prefix ./game/extensions