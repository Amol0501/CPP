#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class Tree{
    public:
        Node *root = NULL;

        void create();
        void inorder(Node *p);
};

void Tree::create(){
    Node *p;
    queue<Node* > q;

    root = new Node;
    int x;
    cout << "Enter the root Node: ";
    cin >> x;
    root -> data = x;
    root -> left = root -> right = NULL;

    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the data of left child of " << p -> data << ": ";
        cin >> x;

        if(x != -1){
            Node *t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> left = t;
            q.push(p -> left);
        }

        cout << "Enter the data of right child of " << p -> data << ": ";
        cin >> x;

        if(x != -1){
            Node *t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> right = t;
            q.push(p -> right);
        }
    }
}

bool isLeaf(Node *p){
    if(p -> left || p -> right)
        return false;
    return true;
}

void leftBoundary(Node *p, vector<int> &ans){
    Node *t = p -> left;
    while(t){
        if(!isLeaf(t))
            ans.push_back(t -> data);
        if(t -> left)
            t = t -> left;
        else
            t = t -> right;
    }
}

void rightBoundary(Node *p, vector<int> &ans){
    vector<int> temp;

    Node *t = p -> right;
    while(t){
        if(!isLeaf(t))
            temp.push_back(t -> data);
        if(t -> right)
            t = t -> right;
        else
            t = t -> left;
    }

    for(int i = temp.size() - 1; i >= 0; i--){
        ans.push_back(temp[i]);
    }
}

void leafBoundary(Node *p, vector<int> &ans){
    if(isLeaf(p)){
        ans.push_back(p -> data);
        return;
    }

    if(p -> left)
        leafBoundary(p -> left, ans);
    if(p -> right)
        leafBoundary(p -> right, ans);
    
}
vector<int> boundary(Node *p){
    vector<int> ans;

    if(p == NULL)
        return ans;
    if(!isLeaf(p))
        ans.push_back(p -> data);
    leftBoundary(p, ans);
    leafBoundary(p, ans);
    rightBoundary(p, ans);
    return ans;
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
    // t.inorder(t.root);
    vector<int> v = boundary(t.root);
    for(int i = 0; i < v.size(); i++){
        // cout << "shg";
        cout << v[i] << " ";
    }
    // cout << "wagm,f";
    return 0;
}