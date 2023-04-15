#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
}*first;

void end_insertion(int ele){
    node *p = first;
    if(p == NULL){
        node *t = new node;
        t -> data = ele;
        t -> next = first;
        first = t;
    }

    else{
        node *t = new node;
        t -> data = ele;
        t -> next = NULL;
        while(p -> next != NULL){
            p = p -> next;
        }
        p -> next = t;
        p = t;
    }
}
void starting_insrtion(int ele){
    node *t = new node;
    t -> data = ele;
    t -> next = first;
    first = t;
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
void e_deletion(){
    node *p = first;
    while(p -> next -> next != 0){
        p = p -> next;
    }
    p -> next = NULL;
}

void deletion_pos(int pos){
    if(pos == 0){
        node *p = first;
        first = first -> next;
        p -> next = NULL;
        free(p);
        return;
    }
    node *p = first;
    node *q = new node;
    for(int i = 0; i < pos - 1; i++){
        p = p -> next;
    }
    q = p -> next;
    p -> next = q -> next;
    q -> next = NULL;
    free(q);
}

void display(node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main(){
    starting_insrtion(2);
    end_insertion(1);
    end_insertion(2);
    end_insertion(3);
    end_insertion(4);
    sum_count();
    cout << endl;
    display(first);
    cout << endl;
    e_deletion();
    deletion_pos(0);
    display(first);
    return 0;
}