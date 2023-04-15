#include<iostream>
using namespace std;
int b_search(int s, int e, int arr[], int key){
    int mid;
    if(s <= e){    
        mid = s + (e - s) / 2;
        if(key == arr[mid]){
            return mid;
        }
        else if (key < arr[mid]){
            return b_search(s, mid - 1, arr, key);
        }
        else{
            return b_search(mid + 1, e, arr, key);
        }
    }
    return -1;
    
}
int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 10;
    cout << b_search(0, 9, a, key);
    return 0;
}