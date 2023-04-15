#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        Node *left;
        int data;
        Node *right;
};

class Tree{
    public:
        Node *root = NULL;

        void create();
        void inorder(Node *p);
};

void Tree::create(){
    Node *p, *t;
    queue<Node *> q;
    int x;
    cout << "Enter the root value: ";
    cin >> x;

    root = new Node;
    root -> data = x;
    root -> left = root -> right = NULL;
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the value of left child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> left = t;
            q.push(p -> left);
        }

        cout << "Enter the value of right child of " << p -> data <<": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> right = t;
            q.push(p -> right);
        }
    }
}

void Tree::inorder(Node *p){
    if(p){
        inorder(p -> left);
        cout << p -> data << " "; 
        inorder(p -> right);
    }
}

bool isIdentical(Node *p, Node *q){
    if(p == NULL || q == NULL)
        return p == q;

    return p -> data == q -> data && isIdentical(p -> left, q -> left) && isIdentical(p -> right, q -> right);
}
int main(){
    Tree t, r;
    cout << "For first tree " << endl;
    t.create();
    t.inorder(t.root);

    cout << "\nFor second tree " << endl;
    r.create();
    r.inorder(r.root);
    if(isIdentical(t.root, r.root))
        cout << "\nTrue";
    else
        cout << "\nFalse";
    
    return 0;
}