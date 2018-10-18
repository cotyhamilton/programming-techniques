// Coty Hamilton : the bases are loaded : 355 : cotyhamilton

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    string nums = "0123456789ABCDEF";

    unordered_map<int, char> chars;

    unordered_map<char, int> digits;

    int fromBase, toBase;

    long aux;

    string number, answer;

    bool valid;

    for (int i = 0; i < nums.length(); i++) {

        // map from digits to chars

        chars[i] = nums[i];

        // map from chars to digits

        digits[nums[i]] = i;

    }

    while (cin >> fromBase) {

        cin >> toBase >> number;

        valid = true;

        for (auto i : number) {

            // If there is a digit (or letter) larger than base allows then
            // number is not allowed

            if (digits[i] >= fromBase || (i != '0' && !digits[i])) {

                valid = false;

                break;

            }


        }

        if (valid) {

            aux = 0;

            answer = "";

            // convert to base 10

            for (int i = 0; i < number.length(); i++) {

                aux = aux * fromBase + digits[number[i]];

            }

            // convert to other base from 10

            do {

                answer = chars[aux % toBase] + answer;

                aux /= toBase;

            }

            while (aux != 0);

            cout << number << " base " << fromBase << " = " << answer << " base " << toBase << endl;
        
        }

        else {

            cout << number << " is an illegal base " << fromBase << " number" << endl;

        }

    }



    return 0;

}