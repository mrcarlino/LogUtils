# LogUtils - C++ Logging Library

A C++ utility library for lightweight logging of specified severity.
Built for simplicity, speed, and ease of use.

## Features

- Cross-platform and dependency-free
- Designed to work with CMake projects
- Preconfigured for use in VS Code

## Project Structure
```
LogUtils/
├── inc/
├── src/
├── tests/
├── CMakeLists.txt
├── README.md
└── .vscode/
```

## Build Instructions

### Prerequisites

- CMake (v3.10+)
- Ninja (recommended)
- g++ (via MSYS2 or WSL for Windows)
- VS Code (with CMake Tools + C++ extensions)

### Build with Visual Studio Code

1. Clone the repo
2. Open it in VS Code
3. Press `Ctrl+Shift+B` to build
4. Press `F5` to run or debug

### Build with CLI
```
cmake -S . -B build -G Ninja
cmake --build build
./build/LogUtils             # Or .exe on Windows
```

## Notes

Make sure `miDebuggerPath` in `.vscode/launch.json` points to your local gdb executable, typically:
C:/msys64/ucrt64/bin/gdb.exe

## Author

Built by Matt Carlino as a learning project and utility for future C++ work.
