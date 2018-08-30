// Coty Hamilton : cost cutting : 11727 : cotyhamilton

#include <iostream>

using namespace std;

int main() {

    int numOfEntries, caseNum = 1, firstValue, secondValue, thirdValue;

    cin >> numOfEntries;

    for (int i = 0; i < numOfEntries; i++) {

        cin >> firstValue >> secondValue >> thirdValue;

        cout << "Case " << caseNum++ << ": ";

        if (firstValue < secondValue) {

            if (secondValue < thirdValue) {

                cout << secondValue;
            }

            else if (firstValue > thirdValue) {

                cout << firstValue;

            }

            else {

                cout << thirdValue;

            }

        }

        else {

            if (firstValue < thirdValue) {

                cout << firstValue;

            }

            else if (secondValue > thirdValue) {

                cout << secondValue;

            }

            else {

                cout << thirdValue;

            }

        }

        cout << endl;
    }

    return 0;

}