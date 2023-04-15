#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
}*front = NULL, *rear = NULL;

void enqueue(int ele){
    node *t = new node;
    if(t == NULL){
        cout << "Queue is Full\n";
    }
    else{
        t -> data = ele;
        t -> next = NULL;
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear -> next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    if(front == rear)
        cout << "Queue is Emply\n";
    else{
        node *p = front;
        front = front -> next;
        x = p -> data;
        free(p);
    }
    return x;
}

void display(){
    node *p = front;
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    display();
    return 0;
}