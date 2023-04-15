#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class BST{
    public: 
        Node *root = NULL;

        void insert(int key);
        Node *Rinsert(Node *p, int key);
        void inorder(Node *p);
        Node *search(int key);
        
};

void BST::insert(int key){
    Node *t = root;
    Node *p, *r;
    if(root == NULL){
        p = new Node;
        p -> data = key;
        p -> lchild = p -> rchild = NULL;
        root = p;
        return;
    }
    while(t){
        r = t;
        if(key < t -> data)
            t = t -> lchild;
        else if(key > t -> data)
            t = t -> rchild;
        else
            return;
    }

    p = new Node;
    p -> data = key;
    p -> lchild = p -> rchild = NULL;
    if(key < r -> data){
        r -> lchild = p;
    }
    else
        r -> rchild = p;
}

Node *BST::Rinsert(Node *p, int key){
    Node *t = NULL;
    if(p == NULL){
        t = new Node;
        t -> data = key;
        t -> lchild = t -> rchild = NULL;
        return t;
    }
    if(p -> data > key){
        p -> lchild = Rinsert(p -> lchild, key);
    }
    else if(p -> data < key){
        p -> rchild = Rinsert(p -> rchild, key);
    }
    return p;
}

void BST::inorder(Node *p){
    if(p){
        inorder(p -> lchild);
        cout << p -> data << " ";
        inorder(p -> rchild);
    }
}

Node *BST::search(int key){
    Node *t = root;
    while(t){
        if(t -> data == key)
            return t;
        else if(t -> data > key)
            t = t -> lchild;
        else
            t = t -> rchild;
    }
    return NULL;
}
int main(){
    BST b;
    b.root = b.Rinsert(b.root, 10);
    b.Rinsert(b.root, 5);
    b.Rinsert(b.root, 20);
    b.Rinsert(b.root, 8);
    b.Rinsert(b.root, 30);
    b.inorder(b.root);
    Node *temp;
    temp = b.search(40);
    cout << endl;
    if(temp != NULL){
        cout << "Element found\n";
    }
    else
        cout << "Element Not found\n";

    return 0;
}