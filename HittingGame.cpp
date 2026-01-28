#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Write C++ code to represent a hitting game by using OOP concept. The details are as follows:
This game is being played between two teams (i.e. your team and the enemy team). The total
number of players in your team is randomly generated and stored accordingly. The function
generates a pair of numbers and matches each pair. If the numbers get matched, the following
message is displayed: “Enemy got hit by your team!” Otherwise, the following message is
displayed: “You got hit by the enemy team!” The number of hits should be equal to the number
of players in your team. The program should tell the final result of your team by counting the
hits of both the teams.
*/

class HittingGame {
private:
    int players;
    int yourHits;
    int enemyHits;

public:
    HittingGame() {
        yourHits = 0;
        enemyHits = 0;
        srand(time(0));
    }

    void generatePlayers() {
        players = rand() % 5 + 1;
        cout << "Total No. Of Players in your team: " << players << endl << endl;
}

    void playGame() {
        for (int i = 1; i <= players; i++) {
            int num1 = rand() % 5 + 1;
            int num2 = rand() % 5 + 1;

            cout << "Pair of numbers:\n";
            cout << "Number1: " << num1 << endl;
            cout << "Number2: " << num2 << endl;

            if (num1 == num2) {
                cout << "Enemy got hit by your team!" << endl << endl;
                enemyHits++;
            } else {
                cout << "You got hit by the enemy team!" << endl << endl;
                yourHits++;
            }
        }
    }

    void displayResult() {
        cout << "Game Over! ";

        if (enemyHits > yourHits)
            cout << "You won" << endl;
        else if (enemyHits < yourHits)
            cout << "You lost" << endl;
        else
            cout << "It's a draw" << endl;
    }
};

int main() {
    HittingGame game;

    game.generatePlayers();
    game.playGame();
    game.displayResult();

    return 0;
}
