# Coin Master Game

This is a simple implementation of the popular mobile game "Coin Master" in C++. The game allows players to spin a slot machine to earn coins, build and upgrade their village, and defend it from attacks. I did this small project during the end of my first year in University of Dhaka.

## Features

- **Player Stats**: Displays the current player's statistics.
- **Spin**: Spins the slot machine to earn coins.
- **Village Shop**: Allows players to upgrade various parts of their village.
- **Village Info**: Provides information about the player's village.
- **Exit**: Quits the game.

## Functions

The game is implemented using several functions, including:

- `printStats()`: Prints the current player's statistics.
- `spin()`: Spins the slot machine and updates the player's coin count.
- `upgradeVillageHouse()`, `upgradeVillageStatue()`, `upgradeVillageGarden()`, `upgradeVillageFarm()`, `upgradeVillageBoat()`: Upgrades various parts of the player's village.
- `getVillageInfo()`: Provides information about the player's village.
- `isVillageAttacked()`: Checks if the player's village has been attacked.
- `isSheildLeft()`, `sheildDecrease()`: Manages the player's shield count for defending against attacks.
- `getNumOfSpins_left()`, `giveNewSpins()`: Manages the player's spin count.

## How to Run

To run this game, you need a C++ compiler. Follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the directory containing the game files in your terminal.
3. Compile the game using your C++ compiler (for example, by running `g++ main.cpp -o coinmaster`).
4. Run the game by typing `./coinmaster`.

Enjoy playing Coin Master!
