// COMSC-210 | Lab 30 | Alexander Sierra
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

const int CITIZENS = 0, IMMIGRANTS = 1, SUPPLIES = 2;

void simulateCountry(map<string, vector<list<string>>>&, int);

int main() {
    srand(time(0));
    //declarations
    map<string, vector<list<string>>> country;

    string region, name;
    ifstream fin ("citizens.txt");
    ifstream fin2 ("supplies.txt");

    //reading data
    if (fin.good()) {
        while (fin >> region >> name) {
            country[region].resize(3);
            country[region][CITIZENS].push_back(name);
        }
        fin.close();
    }
    else {
        cout << "citizens file not found." << endl;
    }

    if (fin2.good()) {
        while (fin2 >> region >> name) {
            country[region].resize(3);
            country[region][SUPPLIES].push_back(name);
        }
        fin2.close();
    }
    else {
        cout << "supplies file not found." << endl;
    }

    //outputs initial state of country
    cout << "Country has been established" << endl;
    for (auto pair : country) {
        cout << "Region: " << pair.first << endl;

        cout << "Citizens: ";
        for (auto p : pair.second[CITIZENS]) {
            cout << p << " ";
        }
        cout << endl << "Immigrants:";
        cout << endl << "Supplies: ";
        for (auto i : pair.second[SUPPLIES]) {
            cout << i << " ";
        }
        cout << endl << endl;
    }

    //simulates regions in country
    simulateCountry(country, 3);
    cout << endl;

    //outputs final state of country
    cout << "Final state of the country" << endl;
    for (auto pair : country) {
        cout << "Region: " << pair.first << endl;

        cout << "Citizens: ";
        for (auto c : pair.second[CITIZENS]) {
            cout << c << " ";
        }
        cout << endl << "Immigrants: ";
        for (auto i : pair.second[IMMIGRANTS]) {
            cout << i << " ";
        }
        cout << endl << "Supplies: ";
        for (auto s : pair.second[SUPPLIES]) {
            cout << s << " ";
        }
        cout << endl << endl;
    }
    return 0;
}

//simulates a country with time periods of years
void simulateCountry(map<string, vector<list<string>>>& country, int years) {
    for (int t = 1; t <= years; t++) {
        cout << "year " << t << endl;
        for (auto& pair : country) {
            string region = pair.first;
            auto& data = pair.second;

            //random actions that could happen
            int change = rand() % 6;
            if (change == 0) {
                string immigrant = "Immigrant " +to_string(t);
                data[IMMIGRANTS].push_back(immigrant);
                cout << immigrant << " has immigrated to this country and now lives in the " << region << endl;
            }
            else if (change == 1) {
                if (!data[SUPPLIES].empty()) {
                    data[SUPPLIES].pop_front();
                    cout << "A supply has been used in the " << region << endl;
                }
                else {cout << region << " has no supplies to use";}
            }
            else if (change == 2) {
                if (!data[CITIZENS].empty()) {
                    cout << data[CITIZENS].front() << " left the " << region << " and emigrated" << endl;
                    data[CITIZENS].pop_front();
                }
                else {cout << region << " has no residents";}
            }
        }
    }
}