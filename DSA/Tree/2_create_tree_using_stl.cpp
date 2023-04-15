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
        void inorder(Node *p);
        void postorder(Node *p);
        void levelorder(Node *p);
        int height(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    queue<Node*> q;
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
        
        cout << "Enter left child of "<< p -> data << ": ";
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

void Tree::inorder(Node *p){
    if(p){
        inorder(p -> lchild);
        cout << p -> data << " ";
        inorder(p -> rchild);
    }
}

void Tree::postorder(Node *p){
    if(p){
        postorder(p -> lchild);
        postorder(p -> rchild);
        cout << p -> data << " ";
    }
}

void Tree::levelorder(Node *p){
    queue<Node*> q;
    cout << root -> data << " ";
    q.push(root);

    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p -> lchild){
            cout << p -> lchild -> data<< " ";
            q.push(p -> lchild);
        }
        if(p -> rchild){
            cout << p -> rchild -> data << " ";
            q.push(p -> rchild);
        }
    }
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

    if(l>r){
        return l + 1;
    }
    else{
        return r + 1;
    }
}
int main(){
    Tree t;
    t.createTree();
    cout << "Preorder = ";
    t.preorder(t.root);
    cout << "\nInorder = ";
    t.inorder(t.root);
    cout << "\nPostorder = ";
    t.postorder(t.root);
    cout << "\nLevelorder = ";
    t.levelorder(t.root);
    cout << "\nHeight = ";
    cout << t.height(t.root);
    return 0;
}