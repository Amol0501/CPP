#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
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

        void print(){
            for(auto i:adj){
                cout << i.first << " -> ";
                for(auto j:i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }
        }

        void BFS(int s, int n){
            
            queue<int> q;

            q.push(s);
            visited[s] = 1;

            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                cout << front << " ";
                for(auto i:adj[front]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
            
            // for isolated Nodes
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    BFS(i, n);
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
        g.addEdge(u, v, 0);
    }

    // g.print();
    
    g.BFS(2, n);
    return 0;
}

// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4
// Your graph is :: 
// 4 -> 3, 0,
// 0 -> 1, 4,
// 1 -> 0, 2, 3,
// 2 -> 1, 3, 
// 3 -> 2, 1, 4,