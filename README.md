# Copilot training sample code

## Prerequisites
- Latest version of VS Code and the following extensions (alternatively, you can use CLion but not all features are available):
  - C/C++
  - C/C++ Extensions Pack
  - CMake Tools
  - GitHub Copilot
  - GitHub Copilot Chat
  - PlantUML (jebbs) -- optional, just for UML diagrams
- C++ Compiler (e.g. Clang, GCC)
  - Windows: If you don't already have a working compiler on your machine, I recommend to install the Microsoft Visual C++ (MSVC) 
    as documented under step 3 of [`these instructions`](https://code.visualstudio.com/docs/cpp/config-msvc)
    - **Note:** As mentioned in the instructions, you should start the "Developer command prompt for VS" and start VS Code from there to ensure that the environment variables are set correctly.  
  - MacOS: `brew install clang`
- CMake
  - Windows: [`Download and run the Windows x64 Installer`](https://cmake.org/download/)
    - Select "Add CMake to system PATH for all users"
    - Confirm the installation: `cmake --version`
  - MacOS: `brew install cmake`
- Ninja
  - MacOS: `brew install ninja`
  - Windows: Often, it's already there. If not, [`download and install Ninja`](https://github.com/ninja-build/ninja/releases)
    - Confirm the installation: `ninja --version`
