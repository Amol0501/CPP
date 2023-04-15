#include<iostream>
using namespace std;
class node{
    public:
        node *prev;
        int data;
        node *next;
}*first;

void end_insertion(int ele){
    node *p = first; 
    node *q = new node;
    while(p -> next != NULL){
        p = p -> next;
    }
    q -> data = ele;
    q -> next = NULL;
    q -> prev = p;
    p -> next = q;
}
void start_insertion(int ele){
    node *p = new node;
    p -> prev = NULL;
    p -> data = ele;
    p -> next = first;
    first = p;
}
void deletion(int pos){
    node *p = first;
    if(pos == 0){
        first = first -> next;
    }
    for(int i = 0; i < pos-1; i++){
        p = p -> next;
    }
    if(p != NULL)
        p -> next = p -> next -> next;
}

void sum_count(){
    node *p = first;
    int sum = 0;
    int count = 0;
    while(p != 0){
        sum = sum + p -> data;
        count++;
        p = p -> next;
    }
    cout << "Sum of elements are: " << sum;
    cout << " and number of elements is: " << count;
}

void display(){
    node *p = first;
    while(p != 0){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(){
    start_insertion(1);    
    end_insertion(2);
    end_insertion(3);
    end_insertion(4);
    end_insertion(5);
    deletion(2);
    display();
    sum_count();
    return 0;
}