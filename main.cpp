// COMSC-210 | Lab 30 | Alexander Sierra
#include <iostream>
#include <map>
#include <list>
#include <fstream>
using namespace std;

void simulateWorld(map<string, array<list<string>,3>>&, int);

int main() {
    srand(time(0));
    map<string, array<list<string>,3>> world;

    string region, name;
    ifstream fin ("players.txt");
    
    return 0;
}