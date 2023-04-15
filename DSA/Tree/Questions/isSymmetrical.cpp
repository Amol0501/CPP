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

bool check(Node *p, Node *q){
    if(p == NULL || q == NULL)
        return p == q;
    
    if(p -> data != q -> data)
        return false;

    return check(p -> left, q -> right) && check(p -> right, q -> left);
}
bool isSymmetric(Node* p){
    if(p == NULL)
        return true;

    return check(p -> left, p -> right);
}
int main(){
    Tree t;
    t.create();
    if(isSymmetric(t.root))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}