// Coty Hamilton : hardwood species : 10226 : cotyhamilton

#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int tests, count = 0;

    double percent;

    string tree;

    map <string, int> treeCount;

    cin >> tests;

    cin.ignore();

    cin.ignore();

    cout << fixed << setprecision(4);

    while (tests--) {

        while (getline(cin, tree) && tree != "") {

            if (!treeCount[tree]) {

                treeCount[tree] = 1;

            }

            else {

                treeCount[tree]++;

            }

            count++;

        }

        for (auto it = treeCount.begin(); it != treeCount.end(); it++) {

            cout << it->first << " " << ((double)it->second / (double)count) * 100 << endl;

        }

        cout << (tests ? "\n" : "");

        treeCount.clear();

        count = 0;

    }
    

    return 0;

}