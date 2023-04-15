#include<bits/stdc++.h>

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
    queue<Node *> q;
    Node *p = NULL, *t;
    root = new Node;
    int x;
    cout << "Enter the root value: ";
    cin >> x;

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

        cout << "Enter the value of right child of " << p -> data << ": ";
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


// vector<int> leftView(Node *p){
//     vector<int> result;
//     queue<pair<Node *, int>> q;   // nishanni k lie
//     int lev = 1;
//     q.push({p, lev});

//     while(!q.empty()){
//         lev++;

//         int size = q.size();
//         vector<int> v;
//         // bool frag = 0;

//         for(int i = 0; i < size; i++){
//             auto front = q.front();
//             q.pop();

//             if(front.first -> left) 
//                 q.push({front.first -> left, lev});
//             if(front.first -> right)
//                 q.push({front.first -> right, lev});

//             v.push_back(front.first -> data);
            
//         }

//         result.push_back(v[0]);
//     }
//     return result;
// }

//             --------------------------using recursion------------------------------------- 

void recursive(Node *p, int level, vector<int> &ans){
    if(p == NULL)
        return;

    if(ans.size() == level)
        ans.push_back(p -> data);
    recursive(p -> left, level + 1, ans);
    recursive(p -> right, level + 1, ans);
}
vector<int> leftView(Node *p){
    vector<int> ans;
    recursive(p, 0, ans);
    return ans;
}
int main(){
    Tree t;
    t.create();
    // t.inorder(t.root);  
    vector<int> v;
    v = leftView(t.root);
    for(auto i:v){
        cout << i << " ";
    }
    return 0;
}