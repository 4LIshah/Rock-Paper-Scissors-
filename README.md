# Rock-Paper-Scissors-

This is a C++ implementation of the classic Rock-Paper-Scissors game. The program allows players to compete against the computer, manage scores, and save/load data to/from a file.

Features
Interactive Gameplay: Play Rock-Paper-Scissors with the computer.
Player Data Management: Add new players or update existing player scores.
Score Saving and Loading: Save scores to a file (scores.txt) and load them on startup.
Visual Output: ASCII art representation for Rock, Paper, and Scissors.
Score Viewing: View all players' scores along with the computer's score.

How to Run
Clone the Repository:
git clone https://github.com/your-repo-name/rock-paper-scissors.git
cd rock-paper-scissors

Compile the Code:
g++ -o game rock_paper_scissors.cpp

Run the Program:
./game

Menu Options
Play Game: Start a new game session. Enter your name, make your choices, and compete against the computer.
View Scores: Display scores of all players and the computer.
Quit: Save all scores and exit the program.

File Structure
scores.txt: Stores the player names, scores, and computer scores. Automatically created if not present.
rock_paper_scissors.cpp: Main program file containing the game logic.

Code Highlights
Player Struct: Defines player properties like name, score, and computer score.
Save and Load Scores: Handles reading/writing player data to a file.
Randomized Choices: Uses rand() for computer's choice, seeded by time(0).
ASCII Art: Provides visual feedback for each choice.
