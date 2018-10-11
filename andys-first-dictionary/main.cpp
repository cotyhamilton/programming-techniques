// Coty Hamilton : andy's new dictionary : 10815 : cotyhamilton

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <regex>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    set<string> dictionary;

    string line, aux = "";

    while(cin >> line) {

        // iterate over string, discard non-alpha characters

        for (int i = 0; i < line.length(); i++) {

            if (!isalpha(line[i])) {

                if (aux != "") {

                    dictionary.insert(aux);

                    aux = "";

                }

            }

            // append aux string with alpha char

            else {

                aux += tolower(line[i]);

            }

        }

        // prevent adding empty string to set

        if (aux != "") {

            dictionary.insert(aux);

            aux = "";

        }
        

    }

    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {

        cout << *it << '\n';

    }


    return 0;

}