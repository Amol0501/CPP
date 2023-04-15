#include<bits/stdc++.h>
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

int maxWidth(Node *p){
    if(p == NULL)
        return 0;
    
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({p, 0});

    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first, last;
        for(int i = 0; i < size; i++){
            int cur_id = q.front().second - min;
            Node *temp = q.front().first;
            q.pop();

            if(i == 0)
                first = cur_id;
            if(i == size - 1)
                last = cur_id;
            if(temp -> left)
                q.push({temp -> left, cur_id*2 + 1});
            if(temp -> right)
                q.push({temp -> right, cur_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}
int main(){
    Tree t;
    t.create();
    cout << maxWidth(t.root);
    return 0;
}