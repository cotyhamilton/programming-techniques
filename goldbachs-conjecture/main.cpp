// Coty Hamilton : goldbach's conjecture : 543 : cotyhamilton

#include <iostream>
#include <bitset>
#include <vector>
#include <math.h>

using namespace std;

#define endl '\n'

int sieve_size;

bitset<1000000> sieve;

vector<int> primes;

void buildSieve(int upperbound) {

    sieve_size = upperbound + 1;

    int root = sqrt(sieve_size);

    sieve.set();

    for (int i = 2; i <= root; i++) {

        if (sieve[i]) {

            for (int j = i * i; j <= sieve_size; j += i) {

                sieve[j] = 0;

            }

            primes.push_back((int)i);

        }

    }

}


int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int num;

    buildSieve(1000000);

    while (cin >> num && num) {

        for (int i = 0; i < primes.size(); i++) {

            // if number minus prime from vector of primes
            // is also found in vector of primes, print the values

            if (sieve[num - primes[i]]) {

                cout << num << " = " << primes[i] << " + " << num - primes[i] << endl;

                break;

            }

        }

    }
    

    return 0;

}