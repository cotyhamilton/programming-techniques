// Coty Hamilton : factors and factorials : 160 : cotyhamilton

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

#define endl '\n'

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    vector<int> primes = {
        2, 3, 5, 7, 11, 13, 17,
        19, 23, 29, 31, 37, 41,
        43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97
    };

    // for looking up a primes index to save in factors

    vector<int> index(100,0);

    for (int i = 0; i < primes.size(); i++) {

        index[primes[i]] = i;

    }

    int test, aux;

    while (cin >> test && test > 0) {

        vector<int> factors(100,0);

        // for each factor of test factorial

		for (int i = 2; i <= test; i++) {

			aux = i;

            // tallies up all number of 2's

            while (aux % 2 == 0) {

                factors[index[aux]] += 1;

                aux = aux / 2;

            }

            // finds least prime factor, tallies up
            // and goes to next

            for (int j = 3; j <= sqrt(aux); j += 2) {

                while (aux % j == 0) {

                    factors[index[j]] += 1;

                    aux = aux / j;

                }

            }

            // if aux ends up as prime add it

            if (aux > 2) {

                factors[index[aux]] += 1;

            }

		}

		cout << setw(3) << right << test << "! =";

		for (int i = 0; i < primes.size() && primes[i] <= test; i++) {

			if (i > 0 && i % 15 == 0){

				cout << "\n      ";

            }

			cout << setw(3) << right << factors[i];
		}

		cout << endl;
	}

	return 0;

}