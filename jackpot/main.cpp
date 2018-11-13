// Coty Hamilton : jackpot : 10684 : cotyhamilton

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int numBets, bet;

    while (cin >> numBets && numBets != 0) {

        int sum = 0, ans = 0;

        while (numBets--) {

            cin >> bet;

            sum += bet;

            // ans keeps largest streak seen

            ans = max(ans, sum);

            // if sum is negative start new streak

            if (sum < 0) {

                sum = 0;

            }

        }

        if (ans > 0) {

            cout << "The maximum winning streak is " << ans << "." << endl;

        }

        else {

            cout << "Losing streak." << endl;

        }

    }

    return 0;

}