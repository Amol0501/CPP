#include<iostream>
using namespace std;
class Stack{
    public:
        int size;
        int top;
        int *s;
};

void create(Stack *st){
    cout << "Enter the size of Stack: ";
    cin >> st -> size;
    st -> top = -1;
    st -> s = new int[st -> size];
}

void push(Stack *st, int ele){
    if(st ->top == st -> size - 1)
        cout << "Stack Overflow\n";
    else{
        st -> top++;
        st -> s[st -> top] = ele;
    }
}

int pop(Stack *st){
    int x = -1;
    if(st -> top == -1)
        cout << "Stack Underflow\n";
    else{
        x = st -> s[st -> top];
        st -> top--;
    }
    return x;
}


int peek(Stack st, int pos){
    int x = -1;
    if((st.top - pos + 1) < 0){
        cout << "Invalid Position\n";
    }
    else{
        x = st.s[st.top - pos + 1];
    }
    return x;
}


void display(Stack st){
    for(int i = st.top; i >= 0; i--)
        cout << st.s[i] << " ";

}



int main(){
    Stack st;
    create(&st);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    push(&st, 6);
    pop(&st);

    display(st);
    cout << peek(st, 3);
    return 0;
}

