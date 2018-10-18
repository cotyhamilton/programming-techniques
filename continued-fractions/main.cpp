// Coty Hamilton : continued fractions : 834 : cotyhamilton

/*

    tricks of the trade:

        what the heck is a continued fraction

        http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/cfINTRO.html#section1.2

*/

#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int num, den, rem;

    while(cin >> num) {

        cin >> den;

        rem = num % den;

        cout << "[" << num / den;

        num = den;

        den = rem;

        if (den) {
            
            cout << ';' << num / den;

            rem = num % den;

        }

        while (!(rem == 0 || num / den == 0)) {

            num = den;

            den = rem;

            cout << ',' << num / den;

            rem = num % den;

        }

        cout << ']' << endl;

    }

    return 0;

}