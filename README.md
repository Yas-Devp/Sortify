# Sortify

**Sortify** is a command-line puzzle game written in C, inspired by mobile color sorting games. The goal is simple: move colored blocks between tubes until each tube contains blocks of a single color. It’s lightweight, fast, and designed to run smoothly on minimal Linux setups.

## Features

- Terminal-based gameplay with ANSI color rendering
- Random level generation with 2 to 5 colors
- Move counter to track your performance
- Win condition detection
- Modular code structure for easy expansion

## Getting Started

### Requirements

- GCC or any C compiler
- Linux terminal (tested on debian based distro , should work on most distros)
- can also work in windows / macos systems (just compile & build the game ^_^)

### Build

Clone the repository and compile the source:

```bash
gcc sortify.c -o sortify
```

*Run*

```bash
./sortify
```

*Gameplay*

- You’ll be presented with a set of tubes containing colored blocks.
- Use the tube numbers to move blocks from one tube to another.
- Blocks can only be placed on top of matching colors or into empty tubes.
- The game ends when all tubes are sorted by color.

*Roadmap*

Planned improvements for future versions:

- Difficulty selection
- Undo functionality
- Save/load system
- Smarter shuffling to guarantee solvable levels
- More color options and visual polish

*License*

This project is licensed under the MIT License. See the `LICENSE` file for details.

*Author*

Developed by *Yas* — a self-taught C programmer passionate about game logic, minimal design, and building fun experiences in the terminal.


---

If you’d like to contribute, feel free to fork the repo or open an issue. Feedback is always welcome.

