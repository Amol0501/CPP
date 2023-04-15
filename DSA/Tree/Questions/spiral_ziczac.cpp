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

        void insert();
        void inorder(Node *p);
        // vector<int> spiral();
};

void Tree::insert(){
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

// vector<int> Tree::spiral(){

// }
void Tree::inorder(Node *p){
    if(p){
        inorder(p -> lchild);
        cout << p -> data << " ";
        inorder(p -> rchild);
    }
}

vector<int> spiral(Node *p){
    vector<int> result;
    int lev = 1;
    queue<pair<Node*, int>> q; // nishanni
    q.push({p, lev});

    while(!q.empty()){
        lev++;
        int size = q.size();
        vector<int> v;
        bool frag = 0;
        for(int i = 0; i < size; i++){
            auto it = q.front();
            q.pop();

            if(it.first -> lchild)
                q.push({it.first -> lchild, lev});
            if(it.first -> rchild)
                q.push({it.first -> rchild, lev});

            if(it.second % 2 != 0)
                result.push_back(it.first -> data);
            else{
                v.push_back(it.first -> data);
                frag = 1;
            }
   
        }
        if(frag == 1){
                reverse(v.begin(), v.end());
                for(int i = 0; i < v.size(); i++){
                    result.push_back(v[i]); 
                }
            }

    }
    return result;
}
int main(){
    Tree t;
    t.insert();
    // t.inorder(t.root);

    vector<int> v;
    v = spiral(t.root);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}


