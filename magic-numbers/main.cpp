// Coty Hamilton : magic numbers : 471 : cotyhamilton

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// checks whether an int has repeating digits
// returns true if no repeating digits, false otherwise

bool check(long long num) {

    // vector to count occurence of digits, max 10 digits

    vector<int> unique(10, 0);

    while (num != 0) {

        // check if last digit (one's place) has been seen

        if (unique[num % 10]) {

            return false;

        }

        // if not seen, mark its place in unique vector

        unique[num % 10] = 1;

        num /= 10;

    }

    return true;

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int tests;

    long long N, max, dividend, limit = 9876543210;

    cin >> tests;

    while (tests--) {

        cin >> N;

        max = limit / N;

        for (long long i = 1; i <= max; ++i) {

            dividend = N * i;

            // check that both dividend and divisor have
            // no repeating digits
            
            // check dividend first because it is more
            // likely to have repeating digits

            if (check(dividend) && check(i)) {

                cout << dividend << " / " << i << " = " << N << endl;

            }

        }

        cout << (tests ? "\n" : "");

    }

    return 0;

}