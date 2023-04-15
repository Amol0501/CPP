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

Node* Lowest_Common_Ancestor(Node *root, int p, int q){
    if(root == NULL || root -> data == p || root -> data == q)
        return root;

    Node *l = Lowest_Common_Ancestor(root -> left, p, q);
    Node *r = Lowest_Common_Ancestor(root -> right, p, q);

    if(l == NULL)
        return r;
    else if(r == NULL)
        return l;
    else
        return root;
} 
int main(){
    Tree t;
    t.create();
    int p, q;
    cin >> p >> q;
    cout << Lowest_Common_Ancestor(t.root, p, q) -> data;
    return 0;
}