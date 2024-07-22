# VERSE Mac Checker Replica
![image](https://github.com/user-attachments/assets/4732086a-c16f-4b0c-bbd5-43c2477e5bbf)
![image](https://github.com/user-attachments/assets/db649827-84b4-4079-a311-6b3872ab7ff7)




Welcome to the **VERSE Mac Checker Replica** project! This tool is a replica of the original VERSE Mac Checker created by .type_shi. It allows users to check their MAC addresses and compare them with previously saved addresses. This project is built using C++ and utilizes JSON for data storage and retrieval.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [License](#license)

## Features

- 🖥️ **Console Resize**: Adjusts the console window size for better readability.
- 📋 **MAC Address Retrieval**: Fetches the current MAC addresses using the `getmac` command.
- 📝 **JSON Handling**: Saves and reads MAC addresses to and from a JSON file.
- 🔍 **MAC Address Comparison**: Compares current MAC addresses with previously saved addresses.
- 🎨 **Colored Console Output**: Uses ANSI escape codes for colorful console messages.

## Requirements

- Windows Operating System
- C++ Compiler (e.g., GCC, MSVC)
- `json.hpp` library (included in the repository)
- `skStr.h` library (included in the repository)

## Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/type1shi/verse-mac-checker.git
   cd verse-mac-checker-replica
   ```

2. **Install Dependencies**

   Ensure you have the `json.hpp` and `skStr.h` files in the project directory. These files are included in the repository.

3. **Build the Project**

   You can use any C++ compiler to build the project. Here, we provide instructions for building with GCC.

   ```bash
   g++ -o mac_checker main.cpp -luser32
   ```

## Usage

1. **Run the Application**

   After building the project, run the executable.

   ```bash
   ./mac_checker
   ```

2. **Command Line Arguments**

   - `-2`: Display credits and exit.
   - `-credits`: Display credits and exit.
   - `-help`: Display help message and exit.

   Example:

   ```bash
   ./mac_checker -2
   ```

3. **Check MAC Addresses**

   The application will display the current MAC addresses and compare them with previously saved addresses. If differences are found, it will notify you.

## Code Overview

### Includes and Constants

```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include "json.hpp"
#include "skStr.h"
#include <Windows.h>
#include <chrono>
#include <thread>
#include <ctime>
```

- `json.hpp`: Header for JSON handling.
- `skStr.h`: Header for encrypted strings.
- ANSI escape codes for colorful console output.

### Functions

- **getMacAddresses()**: Fetches the current MAC addresses using the `getmac` command.
- **WriteToJson(const std::string& filename, const std::vector<std::string>& macs)**: Saves MAC addresses to a JSON file.
- **ReadFromJson(const std::string& filename)**: Reads MAC addresses from a JSON file.
- **compareMacAddresses(const std::vector<std::string>& currentMacs, const std::vector<std::string>& previousMacs)**: Compares two lists of MAC addresses.
- **resizeConsole(int width, int height)**: Resizes the console window.

### Main Function

```cpp
int main(int argc, char* argv[]) {
    // ... (main function implementation)
}
```

- Handles command-line arguments.
- Fetches and displays current MAC addresses.
- Reads previous MAC addresses from a JSON file.
- Compares current and previous MAC addresses.
- Displays results and instructions.

## License

This project is a replica created for educational purposes and is not intended to harm anyone in the VERSE community. Use responsibly.

---

🌟 **Enjoy using the VERSE Mac Checker Replica!** 🌟

If you encounter any issues or have questions, feel free to open an issue or contact me.

