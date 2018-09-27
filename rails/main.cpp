// Coty Hamilton : rails : 514 : cotyhamilton

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    stack<int> station;

    queue<int> order;

    int numOfCars, car;

    bool exit = false;

    while (true) {

        cin >> numOfCars;

        if (numOfCars == 0) {

            break;

        }

        while (true) {

            for(int i = 0; i < numOfCars; ++i) {
                
                // fill queue with order trains should leave

                cin >> car;

                if (car == 0) {

                    exit = true;

                    break;

                }

                order.push(car);

            }

            if (exit) {

                exit = false;

                break;

            }

            for (int i = 1; i <= numOfCars; ++i) {

                // if car in station is the car that should leave, pop

                while (!station.empty() && station.top() == order.front()) {

                    order.pop();

                    station.pop();

                }

                // if current car does not need to leave then push into station

                if (i != order.front()) {

                    station.push(i);

                }

                // if current car needs to leave pop from order

                else {

                    order.pop();

                }

            }

            while (!station.empty() && station.top() == order.front()) {

                // if car in station is the car that should leave, pop

                order.pop();

                station.pop();

            }

            cout << (station.empty() ? "Yes" : "No") << endl;

            order = queue<int>();

            station = stack<int>();

        }

        cout << endl;

    }


    return 0;

}
