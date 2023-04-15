#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        char data;
        node *next;
}*top = NULL;

void push(char x){
    node *t = new node;
    if(t == NULL){
        cout << "Stack is Full" << endl;
    }
    else{
        t -> data = x;
        t -> next = top;
        top = t;
    }
}

char pop(){
    int x = -1;
    if(top == 0){
        cout << "Stack is Empty" << endl;
    }
    else{
        node *p = top;
        top = top -> next;
        x = top -> data;
        delete p;
    }
    return x;
}
int pre(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

int isEmply(){
    if(top == NULL)
        return 0;
    else
        return 1;
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *inToPost(char *infix){
    char *postfix;
    int len = strlen(infix);
    
}
int main(){
    char str[] = "a+b*c-d/e";     

    return 0;
}