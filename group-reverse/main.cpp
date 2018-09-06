// Coty Hamilton : group reverse : 11192 : cotyhamilton

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int numOfGroups, numOfCharsInGroup;

    string inputString, reversedString = "", aux;

    while (cin >> numOfGroups && numOfGroups != 0) {

        cin >> inputString;

        numOfCharsInGroup = inputString.length() / numOfGroups;

        for (int i = 0; i < numOfGroups; i++) {

            aux = inputString.substr(i * numOfCharsInGroup, numOfCharsInGroup);

            reverse(aux.begin(), aux.end());

            reversedString += aux;

            aux = "";

        }

        cout << reversedString << endl;

        reversedString = "";

    }

    return 0;

}