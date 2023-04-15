#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
}*first;

void create(int arr[], int n){
    node *t, *last;
    first = new node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        t = new node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void check_sort(node *p){
    bool frag = true;
    int n = p -> data;
    p = p -> next;
    while(p != 0){
        if(p -> data >= n){
            n = p -> data;
            p = p -> next;
        }
        else{
            frag = false;
            break;
        }
    }
    if(frag)
        cout << "This Linked list is sorted" << endl;
    else
        cout << "This Linked list is not sorted" << endl;

}
int main(){
    int arr[5] = {1, 2, 3, 4, 2};
    create(arr, 5);
    check_sort(first);
    return 0;
}