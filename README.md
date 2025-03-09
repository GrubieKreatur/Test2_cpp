# Test2_cpp
# Test2_cpp

## Overview

Test2_cpp is a C++ project that implements a Tic-Tac-Toe game featuring multiple player types:

- **Human Player**: Allows a human to play the game.
- **Easy Bot Player**: A bot with basic decision-making capabilities.
- **Normal Bot Player**: A bot with intermediate strategies.
- **Hard Bot Player**: A bot with advanced tactics for challenging gameplay.

The game includes a main menu for navigation and a graphical interface for an enhanced user experience.

## Features

- **Multiple Difficulty Levels**: Choose from Easy, Normal, or Hard bot opponents.
- **Human vs. Bot Gameplay**: Play against the computer at various difficulty settings.
- **Graphical User Interface**: Enjoy a visual representation of the game board and interactions.

## Requirements

- **C++ Compiler**: Ensure you have a C++17 compatible compiler.
- **SFML Library**: The project utilizes the Simple and Fast Multimedia Library (SFML) for graphics rendering.

## Precompiled Version

If you don't want to compile the project yourself, a precompiled version is available as a ZIP archive named TicTacToe.zip. This version is only available for Windows. You can simply download and extract it to play the game without additional setup.

## Setup Instructions

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/GrubieKreatur/Test2_cpp.git
   ```

2. **Navigate to the Project Directory**:

   ```bash
   cd Test2_cpp
   ```

3. **Install SFML**:

    - For Debian-based systems:
      ```bash
      sudo apt-get install libsfml-dev
      ```
    - For other systems, refer to the [SFML installation guide](https://www.sfml-dev.org/tutorials/2.6/start/index.php).

4. **Build the Project Using CMake**:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

5. **Run the Executable**:

   ```bash
   ./Test2_cpp
   ```

## Usage

- Upon launching the game, use the main menu to select the desired game mode.
- Follow on-screen prompts to play the game.
- Enjoy playing Tic-Tac-Toe against various levels of AI opponents.

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

