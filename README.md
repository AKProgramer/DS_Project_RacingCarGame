# Race Car Game Using Data structures in C++

This project implements a race car game in C++ that utilizes various data structures for managing game elements efficiently.

## Data Structure Usage

### Overview

The code is divided into two main parts:

#### Game World and Movement Functions

- `GameElement`: Represents elements in the game world like walls, power-ups, and the character.
- `Queue`: Implements a queue using linked lists for game element management.
- `CollectionOfPowerUps`: Maintains a linked list of collected power-ups.
- `LinkedList`: Represents a linked list of game elements.
- Movement functions: `move`, `turnRight`, `turnLeft`, `back` - Update the game world based on character movement.

#### Automatic Mode and Scorekeeping

- `newGame`: Initializes the game world, creates the maze, places obstacles and power-ups, sets character position.
- Functions for automatic mode movement and scorekeeping: `pressW`, `pressA`, `pressS`, `pressD`.

### Usage

- Play the game in two modes: manual and automatic.
- In manual mode, control the character using arrow keys.
- In automatic mode, the computer controls the character with a predefined algorithm.

### Documentation of Functions

Here is a detailed documentation of the main functions in the code:

#### `newGame(...)`

Initializes the game world with obstacles, power-ups, maze, and character position.

#### `pressW(...)`

Moves the character up and updates the score and display.

Parameters:

- Detailed list of parameters with explanations.

#### Error Handling

Include any error handling information here.
