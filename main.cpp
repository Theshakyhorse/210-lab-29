// COMSC-210 | Lab 30 | Alexander Sierra
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

const int PLAYERS = 0, NPCS = 1, ITEMS = 2;

void simulateWorld(map<string, vector<list<string>>>&, int);

int main() {
    srand(time(0));
    map<string, vector<list<string>>> world;

    string region, name;
    ifstream fin ("players.txt");
    ifstream fin2 ("npcs.txt");
    ifstream fin3 ("items.txt");

    if (fin.good()) {
        while (fin >> region >> name) {
            world[region][PLAYERS].push_back(name);
        }
        fin.close();
    }
    else {
        cout << "Input file not found." << endl;
    }

    if (fin2.good()) {
        while (fin2 >> region >> name) {
            world[region][NPCS].push_back(name);
        }
        fin2.close();
    }
    else {
        cout << "Input file not found." << endl;
    }

    if (fin3.good()) {
        while (fin3 >> region >> name) {
            world[region][ITEMS].push_back(name);
        }
        fin3.close();
    }
    else {
        cout << "Input file not found." << endl;
    }

    simulateWorld(world, 3);
    
    return 0;
}