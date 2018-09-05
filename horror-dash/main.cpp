// Coty Hamilton : horror dash : 11799 : cotyhamilton

#include <iostream>

using namespace std;

int main() {

    int numOfEntries, numOfRunners, aux, max;

    cin >> numOfEntries;

    for (int i = 0; i < numOfEntries; i++) {

        max = 0;

        cin >> numOfRunners;

        for (int j = 0; j < numOfRunners; j++) {

            cin >> aux;

            max = aux > max ? aux : max;

        }

        cout << "Case " << i + 1 << ": " << max << endl;

    }

    return 0;

}