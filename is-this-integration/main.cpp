// Coty Hamilton : is this integration : 10209 : cotyhamilton

/*

    accurate calculation of pi from Competitive Programming; page 28

*/

#include <iostream>
#include <math.h>
#include <typeinfo>
#include <iomanip>

using namespace std;

#define endl '\n'

#define PI (2 * acos(0.0))

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    double a, x, y, z, square, segment, centerSquare;

    cout << fixed << setprecision(3);

    while (cin >> a) {

        square = a * a;

        segment = (PI * square / 12 - (square / 4));

        centerSquare = square * (2 - sqrt(3.0));

        // area of inner shape

        x = centerSquare + segment * 4;

        // area of shapes in corners

        y = (((centerSquare) * sqrt(3.0) / 4) + (segment)) * 4;

        // area of remaining space

        z = square - x - y;

        cout << x << " " << y << " " << z << endl;

    }

    return 0;

}