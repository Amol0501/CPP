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

int height(Node *p){
    if(p == NULL)
        return 0;
    
    int l = height(p -> left);
    int r = height(p -> right);
    if(l == -1 || r == -1)
        return -1;

    if(abs(l - r) > 1)
        return -1;

    return max(l, r) + 1;
}
bool isBalanced(Node *p){
    return height(p) != -1;
}
int main(){
    Tree t;
    t.create();
    t.inorder(t.root);  
    if(isBalanced(t.root)){
        cout << "\ntrue";
    } 
    else{
        cout << "\nfalse";
    }
    return 0;
}