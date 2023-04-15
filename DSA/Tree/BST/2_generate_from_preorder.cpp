#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class preorder{
    public:
        Node *root = NULL;

        void insert(Node *p, int *pre, int n);
        void inorder(Node *p);
};

void preorder::insert(Node *p, int *pre, int n){
    int i = 0;
    Node *t;
    root = new Node;
    root -> data = pre[i++];
    root -> lchild = root -> rchild = NULL;
    p = root;
    stack <Node *> str;

    while(i < n){
        if(pre[i] < p -> data){
            t = new Node;
            t -> data = pre[i++];
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            str.push(p);
            p = t;
        }
        else{
            if(pre[i] > p -> data && pre[i] < (str.empty() ? 100000 : str.top() -> data)){   
                t = new Node;
                t -> data = pre[i++];
                t -> lchild = t -> rchild = NULL;
                p -> rchild = t;
                p = t;
            }
            else{
                p = str.top();
                str.pop();
            }
        }
    }
}

void preorder::inorder(Node *p){
    if(p){
        inorder(p -> lchild);
        cout << p -> data << " ";
        inorder(p -> rchild);
    }
}
int main(){
    preorder p;
    int pre[] = {30 , 20 , 10 , 15 , 25 , 40 , 50 , 45};
    p.insert(p.root, pre, 8);
    p.inorder(p.root);
    return 0;
}