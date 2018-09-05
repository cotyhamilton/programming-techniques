// Coty Hamilton : decoder : 458 : cotyhamilton

#include <iostream>
#include <string>

using namespace std;

int main() {

    string codedString, decodedString = "";

    while (cin >> codedString) {

        for(int i = 0; i < codedString.length(); i ++) {

            decodedString += char(codedString[i] - 7);

        }

        cout << decodedString << endl;

        decodedString = "";

    }

    return 0;

}