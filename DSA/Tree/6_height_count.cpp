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
        int sum(Node *p);
        int height(Node *p);
        int count(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    queue<Node *> q;
    int x;
    cout << "Enter the root element: ";
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

int Tree::sum(Node *p){
    if(p){
        return sum(p -> lchild) + p -> data + sum(p -> rchild);
    }
    return 0;
}

int Tree::height(Node *p){
    int l = 0, r = 0;
    if(p == NULL){
        return 0;
    }
    else{
        l = height(p -> lchild);
        r = height(p -> rchild);
    }

    if(l > r){
        return l + 1;
    }
    else{
        return r + 1;
    }
}

int Tree::count(Node *p){
    if(p){
        return count(p -> lchild) + 1 + count(p -> rchild);
    }
    return 0;
}
int main(){
    Tree t;
    t.createTree();
    cout << t.sum(t.root) << endl;
    cout << t.height(t.root) << endl;
    cout << t.count(t.root);
    return 0;
}