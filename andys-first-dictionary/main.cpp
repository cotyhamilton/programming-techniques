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

        for (int i = 0; i < line.length(); i++) {

            if (!isalpha(line[i])) {

                if (aux != "") {

                    dictionary.insert(aux);

                    aux = "";

                }

            }

            else {

                aux += tolower(line[i]);

            }

        }

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

// cout << (i < end ? " " : "");