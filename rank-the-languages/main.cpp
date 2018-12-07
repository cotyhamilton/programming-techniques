// Coty Hamilton : rank the languages : 10336 : cotyhamilton

/*

    tricks of the trade:

*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

#define endl '\n'

vector<int> states(26);

void countStates(vector<string>&, int, int);
void blobbify(vector<string>&, int, int, char);
void print(int);
bool compare(pair<char, int>, pair<char,int>);

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int tests, height, width;

    string line;

    vector<string> map;

    cin >> tests;

    for (int i = 0; i < tests; i++) {

        cin >> height >> width;

        map.clear();

        map.resize(height + 2);

        states.assign(26,0);

        map[0] = (string(width + 2, '.'));

        for (int j = 1; j < height + 1; j++) {

            cin >> line;

            map[j] = ("." + line + ".");

        }

        map[height + 1] = (string(width + 2, '.'));

        countStates(map, height, width);

        print(i);

    }

    return 0;

}

void countStates(vector<string> &map, int height, int width) {

    char aux;

    for (int i = 1; i < height + 1; i++) {

        for (int j = 1; j < width + 1; j++) {

            if (map[i][j] != '.') {

                aux = map[i][j];

                blobbify(map, i, j, aux);

                states[int(aux) - 97] += 1;

            }

        }

    }

}

void blobbify(vector<string> &map, int row, int col, char ch) {

    if (map[row][col] != ch) {

        return;

    }

    if (ch == map[row + 1][col]) {

        map[row][col] = '.';

        blobbify(map, row + 1, col, ch);

    }

    if (ch == map[row][col + 1]) {

        map[row][col] = '.';

        blobbify(map, row, col + 1, ch);

    }

    if (ch == map[row - 1][col]) {

        map[row][col] = '.';

        blobbify(map, row - 1, col, ch);

    }

    if (ch == map[row][col - 1]) {

        map[row][col] = '.';

        blobbify(map, row, col - 1, ch);

    }

    map[row][col] = '.';

    return;

}

void print(int test) {

    vector<pair<char, int> > pairs;

    for(int i = 0; i < 26; i++) {

        if (states[i] >= 1) {

            pairs.push_back(make_pair(char(i + 97), states[i]));

        }

    }

	sort(pairs.begin(), pairs.end(), compare);

    cout << "World #" << test + 1 << endl;

    for (auto it = pairs.begin(); it != pairs.end(); it++) {

        cout << it->first << ": " << it->second << endl;

    }
}

bool compare(pair<char, int> a, pair<char,int> b) {

    if (a.second == b.second) {

        return a.first < b.first;

    }

    else { 

        return a.second > b.second;

    }

}