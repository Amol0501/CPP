#include<iostream>
#include<queue>
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
        
        void createTree();
        void preorder(Node *p);
        void levelorder(Node *p);
        int sum(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    queue<Node *> q;
    int x;
    cout << "Enter root element: ";
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
    if(p){
        cout << p -> data << " ";
        preorder(p -> lchild);
        preorder(p -> rchild);
    }
}

void Tree::levelorder(Node *p){
    queue<Node *> q;
    cout << root -> data << " ";
    q.push(root);

    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p -> lchild){
            cout << p -> lchild -> data << " ";
            q.push(p -> lchild);
        }

        if(p -> rchild){
            cout << p -> rchild -> data << " ";
            q.push(p -> rchild);
        }
    }
}

int Tree::sum(Node *p){
    if(p != NULL){
        return sum(p -> lchild) + p -> data + sum(p -> rchild);
    }
    return 0;
}


int main(){
    Tree t;
    t.createTree();
    // t.preorder(t.root);
    // cout << "\n";
    // t.levelorder(t.root);
    cout << t.sum(t.root);
    return 0;
}