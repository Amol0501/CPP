#include<iostream>
using namespace std;

class Queue{
    public:
        int size;
        int front;
        int rear;
        int *q;
};

void create(Queue *q){
    cout << "Enter the size of Queue: ";
    cin >> q -> size;
    q -> front = -1;
    q -> rear = -1;
    q -> q = new int[q -> size];
}

void enqueue(Queue *qt, int ele){
    if(qt-> rear == qt-> size - 1){
        cout << "Queue is Full\n";
        return;
    }
    else{
        qt -> rear++;
        qt -> q[qt -> rear] = ele;
    }
}

int dequeue(Queue *qt){
    int x = -1;
    if(qt -> front == qt -> rear){
        cout << "Queue is Empty\n";
    }
    else{
        qt -> front++;
        x = qt -> q[qt -> front];
    }
    return x;
}
    
void display(Queue qt){
    for(int i = qt.front+1; i <= qt.rear; i++){ 
        cout << qt.q[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(q);
    cout << dequeue(&q) << endl;
    enqueue(&q, 60);
    display(q);

    return 0;
}