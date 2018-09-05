// Coty Hamilton : wertyu : 10082 : cotyhamilton

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string unLefted, lefted = "";

    vector<int> shiftTable { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ';', 
                        ' ', ' ', ' ', ' ', 'M', '0', ',', '.', '9',
                        '`', '1', '2', '3', '4', '5', '6', '7', '8',
                        ' ', 'L', ' ', '-', ' ', ' ', ' ', 'A', 'V',
                        'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J',
                        'K', 'N', 'B', 'I', 'O', 'Q', 'E', 'A', 'R',
                        'Y', 'C', 'Q', 'Z', 'T', 'Z', 'P', ']', '['};

    while (getline(cin, unLefted)) {

        for(char& c : unLefted) {
            
            lefted += shiftTable[int(c) - 32];
        
        }

        cout << lefted << endl;

        lefted = "";

    }

    return 0;

}
