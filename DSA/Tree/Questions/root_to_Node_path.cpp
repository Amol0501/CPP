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

bool findPath(Node *p, vector<int> &ans, int x){
    if(!p)
        return false;
    
    ans.push_back(p -> data);

    if(p -> data == x)
        return true;

    if(findPath(p -> left, ans, x) || findPath(p -> right, ans, x)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> root_to_Node(Node *p, int x){
    vector<int> ans;
    if(p == NULL)
        return ans;
    
    findPath(p, ans, x);
    return ans;
}
int main(){
    Tree t;
    t.create();

    int x;
    cout << "Enter the Node Value: ";
    cin >> x;
    
    vector<int> v;
    v = root_to_Node(t.root, x);
    for(auto i:v){
        cout << i << " ";
    }
    return 0;
}