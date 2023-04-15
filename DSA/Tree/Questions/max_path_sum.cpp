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

int height(Node *p, int &sum){  // & is important 
    if(p == NULL)
        return 0;

    int l = height(p -> left, sum);
    int r = height(p -> right, sum);

    sum = max(l + r + p -> data, sum);
    return max(l, r) + p -> data;
}
int max_path_sum(Node *p){
    int sum = INT16_MIN;
    height(p, sum);
    return sum;
}
void Tree::inorder(Node *p){
    if(p){
        inorder(p -> left);
        cout << p -> data << " "; 
        inorder(p -> right);
    }
}

int main(){
    Tree t;
    t.create();
    t.inorder(t.root);  
    cout << endl << max_path_sum(t.root);
    return 0;
}