// Coty Hamilton : there's treasure everywhere : 587 : cotyhamilton

/*

    tricks of the trade:

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <math.h>
#include <iomanip>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int aux, count = 0;

    double distance, diagonal = sqrt(2)/2;

    string direction, directions, cardinal = "NESW";

    pair<double, double> treasure;

    unordered_map<string, pair<double,double>> move ({
        {"N", make_pair(0,1)},
        {"NE", make_pair(diagonal,diagonal)},
        {"E", make_pair(1,0)},
        {"SE", make_pair(diagonal,-(diagonal))},
        {"S", make_pair(0,-1)},
        {"SW", make_pair(-(diagonal),-(diagonal))},
        {"W", make_pair(-1,0)},
        {"NW", make_pair(-(diagonal),diagonal)},
    });

    cout << fixed << setprecision(3);

    while(getline(cin, directions) && directions != "END") {
        
        count++;

        treasure.first = treasure.second = distance = aux = 0;

        direction = "";

        for(int i = 0; i < directions.length(); i++) {

            // Uses Horner's rule to get number of steps

            if(isdigit(directions[i])) {

                aux = aux * 10 + (directions[i] - '0');

            }

            // If char in input is not a direction or number calculate location of treasure

            else if (cardinal.find(directions[i]) == string::npos) {

                treasure.first += move[direction].first * aux;

                treasure.second += move[direction].second * aux;

                aux = 0;

                direction = "";

            }

            // If char is a direction

            else {

                direction += directions[i];

            }

        }

        cout << "Map #" << count << "\nThe treasure is located at (" << treasure.first << "," << treasure.second<< ").\n";

        cout << "The distance to the treasure is " << sqrt(treasure.first * treasure.first + treasure.second * treasure.second) << ".\n\n";
        
    }

    return 0;

}