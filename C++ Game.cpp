#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Game {
private:
    int randomNumber;
    int score;
    string playerName;

public:
    Game() {
        score = 0;
    }

    void setPlayerName(string name) {
        playerName = name;
    }

    string getPlayerName() {
        return playerName;
    }

    int getScore() {
        return score;
    }

    void play() {
        srand(time(0));
        randomNumber = rand() % 100 + 1;

        int guess;
        cout << "Ghiceste numarul dintre 1 si 100: ";
        cin >> guess;

        while (guess != randomNumber) {
            if (guess > randomNumber) {
                cout << "Prea mare, incearca dinou!: ";
                score--;
            } else {
                cout << "Prea mic, incearca dinou!: ";
                score--;
            }
            cin >> guess;
        }

        cout << "Bravo ai ghicit! Numarul era: " << randomNumber << endl;
        score++;
    }
};

int main()
{
    Game game;
    cout << "Introdu numele tau: ";
    string name;
    cin >> name;
    game.setPlayerName(name);

    game.play();

    cout << game.getPlayerName() << " scored " << game.getScore() << endl;

    return 0;
}

