#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
}*top;

void push(int ele){
    Node *t = new Node;
    if(t == NULL){
        cout << "Stack is Full";
    }
    else{
        t -> data = ele;
        t -> next = top;
        top = t;
    }
}

int pop(){
    int x = -1;
    if(top == NULL)
        cout << "Stack is Emply";
    else{
        Node *t = new Node;
        t = top;
        top = top -> next;
        t -> next = NULL;
        x = t -> data;
        free(t); 
    }
    return x;
}
void display(Node *top){
    while(top != NULL){
        cout << top -> data << " ";
        top = top -> next;
    }

}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    display(top);
    return 0;
}



































// #include<iostream>
// using namespace std;

// class node{
//     public:
//         int data;
//         node *next;
// }*top;

// void push(int x){
//     node *t = new node;
//     if(t == NULL)
//         cout << "Stack is Full\n";
//     else{
//         t -> data = x;
//         t -> next = top;
//         top = t;
//     }
// }

// int pop(){
//     int x = -1;
//     if(top == NULL)
//         cout << "Stack is empty\n";
//     else{
//         node *p = top;
//         top = top -> next;
//         x = p -> data;
//         free(p);
//     }
//     return x;
// }
// int main(){
    
//     return 0;
// }