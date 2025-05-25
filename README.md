# LogUtils - C++ Logging Library

A lightweight, header-based logging utility for C++ with color-coded output, thread-aware IDs, and flexible `<<` streaming support.

## Features

- Color-coded log levels (DEBUG, INFO, WARNING, ERROR, FATAL)
- Timestamped output
- Compact per-thread ID output
- Clean syntax: 'LOGI << "message"' via macros
- Cross-platform and dependency-free
- Thread-safe
- Preconfigured for use in **Cmake + VS Code**

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

## Log Format

YYYY-MM-DD HH:MM:SS [TID N] [LEVEL] message

Example:
```2025-05-25 16:57:53 [TID 1] [DEBUG] int: 11```


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

## Demo

Below is a screenshot of 'LogUtils', demonstrating:

- Timestamped, multi-threaded logs
- Compact thread IDs ('[TID n]')
- Log level coloring
- Streaming of all basic C++ types

<img width="323" alt="image" src="https://github.com/user-attachments/assets/b87aacb8-59dd-4940-9cb2-dc4cee3495e3" />

## License
MIT - see [LICENSE](LICENSE)

## Author

Built by Matt Carlino as a learning project and utility for future C++ work.
