#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph{
    public:
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> visited;

        void addEdge(int u, int v, bool direction){
            adj[u].push_back(v);

            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void DFS(int s){

            cout << s << " ";
            visited[s] = 1;

            for(int i:adj[s]){
                if(!visited[i]){
                    DFS(i);
                }
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

    Graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }

    g.DFS(3);
    return 0;
}