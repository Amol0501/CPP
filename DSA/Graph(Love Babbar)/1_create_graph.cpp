#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph{
    public:
        unordered_map<int, vector<int>> adj;

        // u -> first edge
        // v -> second edge
        // this function is to add edge
        void addEdge(int u, int v, bool direction){
            // direction -> 0 == undirected graph
            // direction -> 1 == directed graph

            //create an edge from u to v
            adj[u].push_back(v);
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printadjlist(){
            for(auto i:adj){
                cout << i.first << " -> ";
                for(auto j:i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};
int main(){
    int n;
    cout << "Enter the number of total nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of total edges: ";
    cin >> m;

    graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        // creating an unordered graph
        g.addEdge(u, v, 0);
    }

    // print graph
    cout << "Your graph is :: \n";
    g.printadjlist();
    return 0;
}