#include<iostream>
using namespace std;

void linear_search(int arr[], int n, int key){
    if(n == -1){
        cout << "Not found";
        return;
    }
    if(arr[0] == key){
        cout << "Found";
    }
    else{
        linear_search(arr + 1, n - 1, key);
    }
}
int main(){
    int arr[10] = {1, 2, 4, 5, 6, 7, 8, 19, 10, 22};
    linear_search(arr, 10 - 1, 22);
    return 0;
}