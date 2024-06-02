# C Programming Course Repository

This GitHub repository contains a collection of C programming projects from the university course "Introduction to Software Engineering and Computers." Among these, the "Cops and Robbers" game simulation stands out as a feature project. It showcases strategic gameplay, where multiple cops chase a single robber across a configurable grid.

## Programs Included

### 1. Basic Arithmetic Operations and String Manipulation

This program (`file1.c`) demonstrates fundamental arithmetic operations including addition, subtraction, multiplication, division, and modulus. It also includes manipulation of ASCII values to create passwords and methods to reverse the digits of an input number.

### 2. Interactive Menu for Mathematical and Logical Operations

In `file2.c`, an interactive menu drives the program, allowing users to choose operations such as analyzing phone numbers, creating ASCII art, generating Mersenne primes, and solving quadratic equations.

### 3. Cops and Robbers Game Simulation

The highlight of this collection, `file3.c`, simulates a strategic game where multiple cops try to catch a single robber on a grid. This file includes complex logic for movement and interaction within the game grid, assessing win conditions, and providing a dynamic gameplay experience.

**Game Details:**
- Players choose the number of cops.
- The game board's size is adjustable.
- The simulation decides randomly or with input where cops and the robber start.
- Players control movements via command-line inputs, with the game providing feedback on possible moves and game status.

### 4. String Comparison and Manipulation Utilities

`file4.c` includes utility functions for comparing two strings to see if they differ by a specified number of characters. It is useful for tasks requiring precise string comparisons and manipulations, such as validating input differences or processing text data.

## How to Run

To compile and run any of these programs, you can use a C compiler like GCC. Here is an example of how to compile and run `file1.c`:

```bash
gcc file1.c -o file1
./file1
```

Replace `file1.c` with other file names to compile and run other programs.
