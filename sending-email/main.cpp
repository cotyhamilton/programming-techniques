// Coty Hamilton : sending email : 10986 : cotyhamilton

/*

    dijkstras shortest path alg from the green book

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    vector<vii> adjList;

    int cases, numServ,cables, servOne, servTwo, auxOne, auxTwo, weight;

    cin >> cases;

    for (int i = 0; i < cases; i++) {

        cin >> numServ >> cables >> servOne >> servTwo;

        adjList.assign(numServ, vii());

        for (int i = 0; i < cables; i++) {

            cin >> auxOne >> auxTwo >> weight;

            adjList[auxOne].push_back(ii(auxTwo, weight));

            adjList[auxTwo].push_back(ii(auxOne, weight));

        }

        vi dist(numServ, INF);
        
        dist[servOne] = 0;

        priority_queue< ii, vector<ii>, greater<ii> > pq;
        
        pq.push(ii(0, servOne));

        while (!pq.empty()) {

            ii front = pq.top();

            pq.pop();

            int d = front.first, u = front.second;

            if (d == dist[u]) {

                for (int j = 0; j < (int)adjList[u].size(); j++) {

                    ii v = adjList[u][j];

                    if (dist[u] + v.second < dist[v.first]) {

                        dist[v.first] = dist[u] + v.second;

                        pq.push(ii(dist[v.first], v.first));

                    }

                }

            }

        }

        cout << "Case #" << i + 1 << ": ";

        if (dist[servTwo] < INF) {

            cout << dist[servTwo] << endl;

        }

        else {

            cout << "unreachable\n";

        }

    }

    return 0;

}