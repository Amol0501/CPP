#include<iostream>
using namespace std;

void binary_search(int arr[], int s, int e, int key){
    if(s > e){
        cout << "Not found";
        return;
    }
    int mid = (s + e)/2;
    if(arr[mid] == key){
        cout << "Found";
        return;
    }
    else if(arr[mid] > key){
        binary_search(arr, s, mid - 1, key);
    }
    else{
        binary_search(arr, mid + 1, e, key);
    }
}
int main(){
    int arr[10] = {1, 2, 4, 5, 6, 7, 8, 10, 19, 22};
    binary_search(arr, 0, 9, 10);
    return 0;
}