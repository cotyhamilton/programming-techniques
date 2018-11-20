// Coty Hamilton : compromise : 531 : cotyhamilton

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define endl '\n'

void readWords(vector<string> &);

string lcs(vector<vector<int> > &, vector<string> &, int, int);

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    string aux;

    vector<string> countryOne;

    vector<string> countryTwo;

    while(cin >> aux) {

        // read in words

        countryOne.push_back(aux);

        readWords(countryOne);
        
        readWords(countryTwo);

        // initialze 2d vector with 0s

        vector <vector <int> > mat(countryOne.size() + 1, vector <int> (countryTwo.size() + 1, 0));

        for (int i = 0; i < countryOne.size() + 1; i++) {

            for (int j = 0; j < countryTwo.size() + 1; j++) {

                if (i == 0 || j == 0) {

                    mat[i][j] = 0;

                }

                // mark shared word

                else if (countryOne[i -1] == countryTwo[j -1]) {

                    mat[i][j] = mat[i-1][j-1] + 1;

                }

                else {

                    mat[i][j] = max(mat[i-1][j], mat[i][j -1]);

                }

            }

        }

        cout << lcs(mat, countryOne, countryOne.size(), countryTwo.size()) << endl;

        countryOne.clear();

        countryTwo.clear();

    }

    return 0;

}

// read words into list

void readWords(vector<string> &wordList) {

    string word;

    while (cin >> word && word != "#") {

        wordList.push_back(word);

    }

}

string lcs(vector<vector<int> > &mat, vector<string> &wordList, int i, int j) {

    string lcs = "";

    while(i && j) {

        // move diagonal

        if (mat[i][j] == mat[i-1][j-1]) {

            i -= 1;

            j -= 1;

        }

        // move up

        else if (mat[i][j] == mat[i-1][j]) {

            i -= 1;

        }

        // move left

        else if (mat[i][j] == mat[i][j - 1]) {

            j -= 1;

        }

        // both lists share a word

        // add it to the result

        // move diagonal

        else {

            lcs = " " + wordList[i - 1] + lcs;

            i -= 1;

            j -= 1;

        }

    }

    return lcs.substr(1);

}

