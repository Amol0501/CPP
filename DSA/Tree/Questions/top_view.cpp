#include<bits/stdc++.h>
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

vector<int> topView(Node *p){
    vector<int> ans;
    if(p == NULL)
        return ans;
    
    queue<pair<Node*, int>> q;
    map<int, int> nodes;

    q.push({p, 0});
    while(!q.empty()){
        auto t = q.front();
        q.pop();

        Node *temp = t.first;
        int x = t.second;

        if(nodes.find(x) == nodes.end())
            nodes[x] = temp -> data;
        if(temp -> left)
            q.push({temp -> left, x - 1});
        if(temp -> right)
            q.push({temp -> right, x + 1});
        
    }

    for(auto i:nodes){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    Tree t;
    t.create();
    vector<int> v;
    v = topView(t.root);
    for(auto i:v){
        cout << i << " ";
    }
    return 0;
}