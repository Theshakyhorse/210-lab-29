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
    //declarations
    map<string, vector<list<string>>> world;

    string region, name;
    ifstream fin ("players.txt");
    ifstream fin2 ("npcs.txt");
    ifstream fin3 ("items.txt");

    //reading data
    if (fin.good()) {
        while (fin >> region >> name) {
            world[region].resize(3);
            world[region][PLAYERS].push_back(name);
        }
        fin.close();
    }
    else {
        cout << "player file not found." << endl;
    }

    if (fin2.good()) {
        while (fin2 >> region >> name) {
            world[region].resize(3);
            world[region][NPCS].push_back(name);
        }
        fin2.close();
    }
    else {
        cout << "npc file not found." << endl;
    }

    if (fin3.good()) {
        while (fin3 >> region >> name) {
            world[region].resize(3);
            world[region][ITEMS].push_back(name);
        }
        fin3.close();
    }
    else {
        cout << "item file not found." << endl;
    }

    //outputs initial state of world
    cout << "Initial state" << endl;
    for (auto pair : world) {
        cout << "Region: " << pair.first << endl;

        cout << "Players: ";
        for (auto p : pair.second[PLAYERS]) {
            cout << p << " ";
        }
        cout << endl << "NPCS: ";
        for (auto n : pair.second[NPCS]) {
            cout << n << " ";
        }
        cout << endl << "Items: ";
        for (auto i : pair.second[ITEMS]) {
            cout << i << " ";
        }
        cout << endl << endl;
    }

    //alters world
    simulateWorld(world, 3);
    cout << endl;

    //outputs final state of world
    cout << "Final state" << endl;
    for (auto pair : world) {
        cout << "Region: " << pair.first << endl;

        cout << "Players: ";
        for (auto p : pair.second[PLAYERS]) {
            cout << p << " ";
        }
        cout << endl << "NPCS: ";
        for (auto n : pair.second[NPCS]) {
            cout << n << " ";
        }
        cout << endl << "Items: ";
        for (auto i : pair.second[ITEMS]) {
            cout << i << " ";
        }
        cout << endl << endl;
    }
    return 0;
}

//simulates a game world for ticks periods of time
void simulateWorld(map<string, vector<list<string>>>& world, int ticks) {
    for (int t = 1; t <= ticks; t++) {
        cout << "tick " << t << endl;
        for (auto& pair : world) {
            string region = pair.first;
            auto& data = pair.second;

            //random actions that could happen
            int change = rand() % 3;
            if (change == 0) {
                string npc = "NPC " +to_string(t);
                data[NPCS].push_back(npc);
                cout << npc << " spawned in " << region << endl;
            }
            else if (change == 1) {
                if (!data[ITEMS].empty()) {
                    data[ITEMS].pop_front();
                    cout << "Item removed from " << region << endl;
                }
                else {cout << region << " has no items";}
            }
            else if (change == 2) {
                if (!data[PLAYERS].empty()) {
                    cout << data[PLAYERS].front() << " left " << region << endl;
                    data[PLAYERS].pop_front();
                }
                else {cout << region << " has no players";}
            }
        }
    }
}