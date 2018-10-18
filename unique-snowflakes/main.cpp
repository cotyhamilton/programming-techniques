// Coty Hamilton : unique snowflakes : 11572 : cotyhamilton

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int cases, numSnowflakes, largest, count, segment, snowflake;

    unordered_map <int, int> snowflakes;

    cin >> cases;

    while (cases--) {

        cin >> numSnowflakes;

        largest = count = segment = 0;

        for (int i = 1; i <= numSnowflakes; ++i) {

            cin >> snowflake;

            // last is equal to the last position a snowflake was seen

            int last = snowflakes[snowflake];

            // check if snowflake has been seen

            if (last) {

                // segment stores the index of the last snowflake that wasn't unique

                segment = max(segment, last);

                // reset count to reflect that the snowflake is not unique

		        count = i - 1 - segment;

            }

            // count stores the number of unique snowflakes that have been seen

            count++;

            // update the map with a snowflake's position

            snowflakes[snowflake] = i;

            // largest is equal to count

            largest = max(largest, count);

        }

        cout << largest << '\n';

        snowflakes.clear();

    }

    return 0;

}