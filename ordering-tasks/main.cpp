// Coty Hamilton : ordering tasks : 10305 : cotyhamilton

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adjList;
vector<bool> visited;
vector<int> order;
 
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
            order.clear();
            adjList.resize(N);
            visited.assign(N, false);
        }
        /*
         * Adding edge to graph
         */ 
        void addEdge(int from, int to) {
            adjList[from].push_back(to);
        }
        /*
         * Add node to order after post order traversal
         * saved in reverse order
         */ 
        void dfs_kinda(int node) {
            visited[node] = true;
            for (int i = 0; i < adjList[node].size(); i++) {
                if(visited[adjList[node][i]] == false) {
                    dfs_kinda(adjList[node][i]);
                }
            }
            order.push_back(node);
        }
};

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int numOfTasks, numOfEdges, first, second;

    while (cin >> numOfTasks >> numOfEdges && numOfTasks != 0) {

        Graph graph(numOfTasks);

        for (int i = 0; i < numOfEdges; i++) {

            cin >> first >> second;

            graph.addEdge(first,second);

        }

        for (int i = 1; i <= numOfTasks; i++) {

            if (visited[i] == false) {

                graph.dfs_kinda(i);

            }

        }

        // print out reverse order

        for (int i = order.size() - 1; i >= 0; i--) {

            cout << order[i];

            cout << (i > 0 ? " " : "");

        }
        
        cout << endl;

    }

    return 0;

}