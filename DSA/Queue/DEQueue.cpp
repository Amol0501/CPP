#include<iostream>
using namespace std;

class queue{
    public:
        int size;
        int rear;
        int front;
        int *Q;
};
void create(queue *qt){
    qt -> size = 10;
    qt -> front = qt -> rear = -1;
    qt -> Q = new int[qt -> size];
}

void enqueue(queue *qt, int ele){
    if(qt -> rear == qt -> size - 1)
        cout << "Queue is Full\n";
    else{
        qt -> rear++;
        qt -> Q[qt -> rear] = ele;
    }
}

int dequeue(queue *qt){
    int x = -1;
    if(qt -> front == qt -> rear)
        cout << "Queue is Empty\n";
    else{
        qt -> front++;
        x = qt -> Q[qt -> front];
    }
    return x;
}

void front_Enqueue(queue *qt, int ele){
    if(qt -> front == -1)
        cout << "Queue is Full\n";
    else{
        qt ->Q[qt -> front] = ele;
        qt -> front--;
    }
}

int end_dequeue(queue *qt){
    int x = -1;
    if(qt -> rear == qt -> front)
        cout << "Queue is Empty\n";
    else{
        x = qt -> Q[qt -> rear];
        qt -> rear--;
    }
    return x;
}

void display(queue qt){
    for(int i = qt.front + 1; i <= qt.rear; i++){
        cout << qt.Q[i] << " ";
    }
    cout << endl;
}
int main(){
    queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 50);
    cout << "Delete from front side: " << dequeue(&q) << endl;
    cout << "Delete from front side: " << dequeue(&q) << endl;
    front_Enqueue(&q, 40);
    cout << "Delete from rear side: " << end_dequeue(&q) << endl;    
    display(q);
    return 0;
}