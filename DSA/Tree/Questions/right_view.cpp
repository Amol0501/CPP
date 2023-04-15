#include<iostream>
#include<vector>
#include<algorithm>
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

        void create();
        void inorder(Node *p);
};

void Tree::create(){
    Node *p, *t;
    queue<Node *> q;

    root = new Node;
    int x;
    cout << "Enter the root Node: ";
    cin >> x;
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    q.push(root);

    while(!q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter the left child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            q.push(p -> lchild);
        }

        cout << "Enter the right child of " << p -> data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            q.push(p -> rchild);
        }
    }
}

// vector<int> rightView(Node *p){
//     vector<int> result;
//     int lev = 1;
//     queue<pair<Node *, int>> q;
//     q.push({p, lev});
//     while(!q.empty()){
//         lev++;
//         int size = q.size();
//         vector<int> v;
        
//         for(int i = 0; i < size; i++){
//             auto it = q.front();
//             q.pop();

//             if(it.first -> lchild){
//                 q.push({it.first -> lchild, lev});
//             }
//             if(it.first -> rchild){
//                 q.push({it.first -> rchild, lev});
//             }

//             v.push_back(it.first -> data);

//         }

//         size = v.size();
//         result.push_back(v[size - 1]);
//     }
//     return result;
// }

//                             ---------------------------------using recursion----------------------------------------
void recursive(Node *p, int level, vector<int> &ans){
    if(p == NULL)
        return;

    if(ans.size() == level)
        ans.push_back(p -> data);
    recursive(p -> rchild, level + 1, ans);
    recursive(p -> lchild, level + 1, ans);
}
vector<int> rightView(Node *p){
    vector<int> ans;
    recursive(p, 0, ans);
    return ans;
}
int main(){
    Tree t;
    t.create();
    // t.inorder(t.root);  
    vector<int> v;
    v = rightView(t.root);
    for(auto i:v){
        cout << i << " ";
    }
    return 0;
}