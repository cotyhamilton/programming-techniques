// Coty Hamilton : vertex : 280 : cotyhamilton

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
int numOfVisited;
queue<int> Q;
 
/*
 * Class Graph
 */ 
class Graph {
    private:
        int N;
    public:
        Graph(int n) {
            N = n + 1;
            adjList.clear();
            adjList.resize(N);
            visited.assign(N, false);
            numOfVisited = 0;
        }
        /*
         * Adding edge to graph
         */ 
        void addEdge(int from, int to) {
            adjList[from].push_back(to);
        }
        /*
         * Finds all vertices accessible from node
         */ 
        void bfs(int node) {
            int u;
            Q.push(node);
            while(!Q.empty()) {
                u = Q.front();
                Q.pop();
                for (int i = 0; i < adjList[u].size(); i++) {
                    if (visited[adjList[u][i]] == false) {
                        visited[adjList[u][i]] = true;
                        numOfVisited++;
                        Q.push(adjList[u][i]);
                    }
                }
            }
        }
};

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int numOfVertices, vertex, aux, tests, testNode;

    while (cin >> numOfVertices && numOfVertices != 0) {

        Graph graph(numOfVertices);

        while (cin >> vertex && vertex != 0) {

            while (cin >> aux && aux != 0) {

                graph.addEdge(vertex, aux);

            }

        }

        cin >> tests;
        
        for (int i = 0; i < tests; i++) {

            cin >> testNode;

            graph.bfs(testNode);

            cout << numOfVertices - numOfVisited;

            for (int i = 1; i <= numOfVertices; i++) {
                
                if (visited[i] != true) {

                    cout << " " << i;

                }

            }
            
            cout << endl;

            visited.assign(numOfVertices + 1, false);

            numOfVisited = 0;

        }

    }

    return 0;

}