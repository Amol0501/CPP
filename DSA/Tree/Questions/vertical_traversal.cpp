// #include<bits/stdc++.h>
#include<iostream>

#include<queue>
#include<map>
#include<set>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class Tree{
    public:
        Node *root = NULL;

        void create();
        void inorder(Node *p);
};

void Tree::create(){
    Node *p;
    queue<Node* > q;

    root = new Node;
    int x;
    cout << "Enter the root Node: ";
    cin >> x;
    root -> data = x;
    root -> left = root -> right = NULL;

    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the data of left child of " << p -> data << ": ";
        cin >> x;

        if(x != -1){
            Node *t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> left = t;
            q.push(p -> left);
        }

        cout << "Enter the data of right child of " << p -> data << ": ";
        cin >> x;

        if(x != -1){
            Node *t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> right = t;
            q.push(p -> right);
        }
    }
}

vector<vector<int>> vertical_traversal(Node *p){
    queue<pair<Node*, pair<int, int>>> q;     // node, vertical, height
    map<int, map<int, multiset<int>>> nodes;

    q.push({p, {0, 0}});
    while(!q.empty()){
        auto t = q.front();
        q.pop();

        Node *temp = t.first;
        int x = t.second.first;
        int y = t.second.second;
        nodes[x][y].insert(temp -> data);
        if(t.first -> left)
            q.push({t.first -> left, {x-1, y+1}});
        if(t.first -> right)
            q.push({t.first -> right, {x+1, y+1}});
    }

    vector<vector<int>> ans;
    for(auto i:nodes){
        vector<int> col;
        for(auto j:i.second){
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
    Tree t;
    t.create();
    vector<vector<int>> v;
    v = vertical_traversal(t.root);
    for(auto i:v){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}