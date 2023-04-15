#include<iostream>
using namespace std;
class Node{
    public:
        char data;
        Node *next;
}*top;

void push(char ele){
    Node *t = new Node;
    if(t == NULL)
        cout << "Stack is Full\n";
    else{
        t -> data = ele;
        t -> next = top;
        top = t;
    }
}

int pop(){
    int x = -1;
    if(top == NULL)
        cout << "Stack is Emply\n";
    else{
        Node *t = top;
        x = t -> data;
        top = top -> next;
        free(t);
    }
    return x;
}

bool isbalance(char *ele){
    for(int i = 0; ele[i] != '\0'; i++){
        if(ele[i] == '(')
            push('(');
        if(ele[i] == ')'){
            if(top != NULL)
                pop();
            else{
                return false;
            }
        }
    }
    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char ele[] = "()())";
    if(isbalance(ele))
        cout << "true";
    else
        cout << "false";
    return 0;
}