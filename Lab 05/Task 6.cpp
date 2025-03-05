#include <iostream>
using namespace std;

class Level {
private:
    int levelNo;
    string description;
public:
    Level() {
    	levelNo = 0;
    	description = "";
	}
    void levelDescription(int num, string desc) {
        levelNo = num;
        description = desc;
    }
    void display() const {
        cout << "  Level " << levelNo << ": " << description << endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level levels[3]; 
    int levelCount;
public:
    VideoGame(string t, string g) {
    	title = t;
		genre = g;
		levelCount = 0;
	}
    
    void addLevel(int num, string desc) {
        if (levelCount < 3) {
            levels[levelCount].levelDescription(num, desc);
            levelCount++;
        } else {
            cout << "Cannot add more levels!\n";
        }
    }
    
    void displayGameDetails() const {
        cout << "Game: " << title << " (" << genre << ")\nLevels:\n";
        for (int i = 0; i < levelCount; i++) {
            levels[i].display();
        }
    }
};

int main() {
    VideoGame game("Maze Runner", "Adventure");
    game.addLevel(1, "Introduction to the Maze");
    game.addLevel(2, "Escape Challenges");
    game.addLevel(3, "Final Boss Fight");
    
    game.displayGameDetails();
    
    return 0;
}
