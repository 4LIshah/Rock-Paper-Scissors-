#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_PLAYERS = 100;

struct Player {
	
                string name;
                int score;
                int computerScore;
                    
    Player()
        : name(""), score(0), computerScore(0) {}

        
    // Parameter constructor
    Player(string n, int s, int cS)
        : name(n), score(s), computerScore(cS) {}
};

void saveScores (const Player players[], int numPlayers) {
    ofstream file("scores.txt");
    if (file.is_open()) {
        for (int i = 0; i < numPlayers; ++i) {
            file << players[i].name << " " 
			 	<< players[i].score << " "
                 << players[i].computerScore << endl;
        }
        file.close();
        cout << "Scores saved successfully.\n";
    } else {
        cerr << "Unable to open file for saving scores.\n";
    }
}

void loadScores(Player players[], int numPlayers) {
    ifstream file("scores.txt");
    if (file.is_open()) {
        numPlayers = 0;
        string name;
        int  score, computerScore;
        while (file >> name >> score >> computerScore &&
               numPlayers < MAX_PLAYERS) {
            players[numPlayers] =
                Player(name, score, computerScore);
            ++numPlayers;
        }
        file.close();
        cout << "Scores loaded successfully.\n";
    } else {
        cerr << "Unable to open file for loading scores.\n";
    }
}
void RSP(int choice) {
    switch (choice) {
   case 1:
        cout << "Rock.\n\n";
        cout << "   _______\n";
        cout << "--'   ____)\n";
        cout << "     (______)   \n";
        cout << "     (_____)  \n";
        cout << "     (____) \n";
        cout << "--.__(___)\n\n";
        break;

    case 2:
        cout << "Paper.\n\n";
        cout << "    _______\n";
        cout << "---'   ____)____\n";
        cout << "          ______)\n";
        cout << "          _______)\n";
        cout << "         _______)\n";
        cout << "---.__________)\n\n";
        break;

    case 3:
        cout << "Scissors.\n\n";
        cout << "    _______\n";
        cout << "---'   ____)____\n";
        cout << "          ______)\n";
        cout << "       __________)\n";
        cout << "      (____)\n";
        cout << "---.__(___)\n\n";
        break;
        
    default:
    	cout<<"Invalid choice!!";
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    int computerScore = 0; 
    int score = 0;
    loadScores(players, numPlayers);
    cout << "\nROCK PAPER SCISSORS\n\n";
    while (true) {
    	cout << endl;
        cout << "1. Play Game\n";
        cout << "2. View Scores\n";
        cout << "3. Quit\n";
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            string playerName;
            cout << "Enter your name: ";
            cin >> playerName;
            while (true) {
                int userChoice;
                cout << '\n' << playerName << ", let's play Rock-Paper-Scissors!\n\n";
                cout << "Enter your choice:\n";
                cout << "1 - Rock\n";
                cout << "2 - Paper\n";
                cout << "3 - Scissors\n\n";
                cin >> userChoice;
                int computerChoice = rand() % 3 + 1;
                cout << "You chose \n\n";
                RSP(userChoice);
				cout << "The computer chose \n\n";
                RSP(computerChoice);

				if ((userChoice == 1 && computerChoice == 3) ||
                    (userChoice == 2 && computerChoice == 1) ||
                    (userChoice == 3 && computerChoice == 2)) {
                    cout << "You win!\n";
	score++;
                    bool playerFound = false;
                    for (int i = 0; i < numPlayers; ++i) {
                        if (players[i].name == playerName) {
                            players[i].score=score;
                            playerFound = true;
                            break;
                        }
                    }
                    if (!playerFound) {
                        // If the player is not found, add a new player
                        if (numPlayers < MAX_PLAYERS) {
                            players[numPlayers] =
                            Player(playerName, score, computerScore);
                            ++numPlayers;
                        } else {
                            cerr << "Maximum number of players reached.\n";
                        }
                    }
                } else if (userChoice == computerChoice) {
                    cout << "It's a tie!\n";
                } else {
                    cout << "Computer wins!\n";
                    computerScore++;
                    bool playerFound = false;
                    for (int i = 0; i < numPlayers; ++i) {
                        if (players[i].name == playerName) {
                            players[i].computerScore=computerScore;
                            playerFound = true;
                            break;
                        }
                    }
                    if (!playerFound) {
                        // If the player is not found, add a new player
                        if (numPlayers < MAX_PLAYERS) {
                            players[numPlayers] =
                                Player(playerName, score, computerScore);
                            ++numPlayers;
                        } else {
                            cerr << "Maximum number of players reached.\n";
                        }
                    }
                }
                cout << "Do you want to play again? (1 for yes, 0 for no): ";
                int playAgain;
                cin >> playAgain;
                if (playAgain != 1) {
                	computerScore = 0;
    				score = 0;

                    break; // Exit the game loop
                }
            }
            system("cls");
            break;
        }
        case 2: {
            // View Scores
            cout << endl;
            cout << "Scores are: \n";
            for (int i = 0; i < numPlayers; ++i) {
                cout << players[i].name << ": " << players[i].score
                     << ", Computer: " << players[i].computerScore << "\n";
            }
            break;
        }
        case 3: {
            // Save Scores and Quit
            saveScores(players, numPlayers);
            cout << "Thanks for playing!\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    return 0;
}

