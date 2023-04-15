#include<iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class queue{
    public:
        int size;
        int rear;
        int front;
        Node **Q;

    queue(int size){
        this -> size = size;
        front = rear = -1;
        Q = new Node *[size];
    }

    void enqueue(Node *ele){
        if(rear == size - 1){
            cout << "queue is Full\n";
            return;
        }
        else{
            rear++;
            Q[rear] = ele;
        }
    }

    Node *dequeue(){
        Node *x = NULL;
        if(rear == front){
            cout << "Queue is emply\n";
        }
        else{
            front++;
            x = Q[front];
        }
        return x;
    }

    bool isEmpty(){
        if(rear == front){
            return true;
        }
        else{
            return false;
        }
    }

    bool full(){
        if(rear == size -1)
            return true;
        return false;
    }
};


class Tree{
    public:
        Node *root;
        Tree(){
            root = NULL;
        };

        void createTree();
        void preorder(Node *p);
        void inorder(Node *p);
        void postorder(Node *p);
        void levelorder(Node *p);
};

void Tree::createTree(){
    Node *t, *p;
    int x;
    queue q(100);
    cout << "Enter the root value: ";
    cin >> x;
    root = new Node;
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty()){
        p = q.dequeue();
        cout << "Enter left child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> lchild = t ->rchild = NULL;
            p -> lchild = t;
            q.enqueue(t);
        }

        cout << "Enter right child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            q.enqueue(t);
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
    queue q(100);
    cout << root -> data << " ";
    q.enqueue(root);
    while(!q.isEmpty()){
        root = q.dequeue();
        if(root -> lchild){
            cout << root -> lchild -> data << " ";
            q.enqueue(root -> lchild);
        }
        if(root -> rchild){
            cout << root -> rchild -> data << " ";
            q.enqueue(root -> rchild);
        }
    }
}

int main(){
    Tree t;
    t.createTree();
    cout << "Preorder = ";
    t.preorder(t.root);
    cout << "\nInorder = ";
    t.inorder(t.root);
    cout << "\nPostOrder = ";
    t.postorder(t.root);
    cout << "\nLevel order = ";
    t.levelorder(t.root);
    return 0;
}