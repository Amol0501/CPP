#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Tree{
    public:
        Node *root = NULL;

        void create();
        void preorder(Node *p);
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
    root -> lchild = root -> rchild = NULL;
    q.push(root);

    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            q.push(t);
        }

        cout << "Enter right child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            q.push(t);
        }
    }
}

void Tree::preorder(Node *p){
    stack<Node *> s;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            cout << p -> data << " ";
            s.push(p);
            p = p -> lchild;
        }
        else{
            p = s.top();
            s.pop();
            p = p -> rchild;
        }
    }
    cout << endl;
}

void Tree::inorder(Node *p){
    stack<Node *> s;
    while(p != NULL || !s.empty()){
        if(p){
            s.push(p);
            p = p -> lchild;
        }
        else{
            p = s.top();
            s.pop();
            cout << p -> data << " ";
            p = p -> rchild;
        }
    }
}


int main(){
    Tree t;
    t.create();
    cout << "Preorder = ";
    t.preorder(t.root);
    cout << "Inorder = ";
    t.inorder(t.root);
    return 0;
}