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

int height(Node *p, int &maxi){
    if(p == NULL)
        return 0;
    int l = height(p -> left, maxi);
    int r = height(p -> right, maxi);

    maxi = max(l + r, maxi);
    return max(l, r) + 1;
}
int diameter(Node *p){
    int maxi = 0;
    height(p, maxi);
    return maxi;
}
int main(){
    Tree t;
    t.create();
    t.inorder(t.root);  
    cout << endl <<diameter(t.root);
    return 0;
}