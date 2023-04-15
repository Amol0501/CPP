#include<iostream>
using namespace std;
class node{
    public:
        char data;
        node *next;
}*first;

void push(char ele){
    node *p = first;
    node *t = new node;
    t -> data = ele;
    t -> next = first;
    first = t;
}

char pop(){
    char x;
    node *p = first;
    if(first == NULL){
        cout << "Stack is empty" << endl;
    }
    else{
        x = first -> data;
        first = first -> next;
        p -> next = NULL;
        free(p);
    }
    return x;
}


char top(){
    node *p = first;
    return p -> data;
}


int per(char x){
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return -1;
}

bool isEmpty(){
    if(first == NULL){
        return true;
    }
    return false;
}


string infix_to_postfix(string s){
    string ans;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
            ans+=s[i];
        }
        else if(s[i] == '('){
            push('(');
        }
        else if(s[i] == ')'){
            while(top() != '('){
                ans+=pop();
            }
            pop();
        }
        else{
            while(!isEmpty() && per(s[i]) <= per(top())){
                ans += pop();
            }
            push(s[i]);
        }
    }

    while(!isEmpty()){
        ans += pop();
    }
    return ans;
}
void display(){
    node *p = first;
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){
    string s = "A*B*C";
    cout <<  infix_to_postfix(s);
    return 0;
}