// Coty Hamilton : stern-brocot tree : 11350 : cotyhamilton

#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

typedef pair<long long, long long> fraction;

void traverse(fraction left, fraction right, string directions) {

    // set direction to L or R

    char direction = directions[0];

    fraction mediant(left.first + right.first, left.second + right.second);

    // pass rest of directions along with current direction

    if (direction == 'L') {

        traverse(left, mediant, directions.substr(1));

    }

    else if (direction == 'R') {

        traverse(mediant, right, directions.substr(1));

    }

    else {

        cout << mediant.first << "/" << mediant.second << endl;

    }

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int cases;

    string directions;

    fraction zero(0,1);

    fraction infinity(1,0);

    fraction answer;

    cin >> cases;

    while (cases--) {

        cin >> directions;

        traverse(zero, infinity, directions);

    }

    return 0;

}