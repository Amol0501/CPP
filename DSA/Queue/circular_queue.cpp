#include<iostream>
using namespace std;
class Queue{
    public:
        int size;
        int rear;
        int front;
        int *Q;
};
void create(Queue *qt){
    qt -> size = 5;
    qt -> rear = -1;
    qt -> front = -1;
    qt -> Q = new int[qt -> size];
}
void enqueue(Queue *qt, int ele){
    if((qt -> rear + 1) % qt -> size == qt -> front){
        cout << "Queue is Full\n";
    }
    else{
        qt -> rear = (qt -> rear + 1) % qt -> size;
        qt -> Q[qt -> rear] = ele;
    }
}

int dequeue(Queue *qt){
    int x = -1;
    if(qt -> rear == qt -> front){
        cout << "Queue is Empty\n";
    }
    else{
        qt -> front = (qt -> front + 1) % qt -> size;
        x = qt -> Q[qt -> front];
    }
    return x;
}

void display(Queue qt){
    int i = (qt.front+1)%qt.size;
    while(i != (qt.rear+1)%qt.size){
        cout << qt.Q[i] << " ";
        i = (i+1)%qt.size;
    }
}
int main(){
    Queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    cout << dequeue(&q) << endl;
    cout << dequeue(&q) << endl;
    enqueue(&q, 50);
    enqueue(&q, 60);
    cout << dequeue(&q) << endl;

    display(q);
    return 0;
}