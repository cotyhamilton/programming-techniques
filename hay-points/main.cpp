// Coty Hamilton : hay points : 10295 : cotyhamilton

#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    string word;

    int num_words, num_descriptions, value, salary;

    map<string,int> points;

    cin >> num_words >> num_descriptions;

    while (num_words--) {

        cin >> word >> value;

        points[word] = value;

    }

    while (num_descriptions--) {

        salary = 0;

        while (cin >> word && word != ".") {

            salary += points[word];

        }

        cout << salary << endl;

    }



    return 0;

}