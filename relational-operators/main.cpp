// Coty Hamilton : relational operators : 11172 : cotyhamilton

#include <iostream>
#include <string>

using namespace std;

int main() {

    int numOfEntries, firstValue, secondValue;

    cin >> numOfEntries;
    
    for (int i = 0; i < numOfEntries; i++) {

        cin >> firstValue >> secondValue;

        if (firstValue == secondValue) {

            cout << '=' << endl;

        }

        else {

            cout << (firstValue < secondValue ? '<' : '>') << endl;

        }

    }

    return 0;

}