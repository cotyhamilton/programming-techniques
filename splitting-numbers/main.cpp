// Coty Hamilton : splitting numbers : 11933 : cotyhamilton

#include <iostream>
#include <bitset>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    long aux;

    bitset<32> a;

    bitset<32> b;

    bool even = true;

    while(cin >> aux && aux) {

        bitset<32> num (aux);

        for(int i = 0; i < 32; ++i) {

            if(num.test(i)) {

                if(even) {

                    a.flip(i);

                }

                else {

                    b.flip(i);

                }
                
                even = !even;

            }

        }

        cout << a.to_ulong() << " " << b.to_ulong() << endl;

        even = true;

        a.reset();

        b.reset();

    }

    return 0;

}