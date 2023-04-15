#include<iostream>
#include<queue>
using namespace std;

int main(){
// --------------------------------------Max heap stl---------------------------------------
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(4);
    pq.push(7);
    pq.push(1);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;


// --------------------------------------Min heap stl---------------------------------------

    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(5);
    minheap.push(2);
    minheap.push(4);
    minheap.push(7);
    minheap.push(1);
    cout << minheap.top() << endl;
    minheap.pop();
    cout << minheap.top() << endl;
    
    return 0;
}



