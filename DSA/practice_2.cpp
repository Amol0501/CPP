// inserting an element in an sorted array

#include<iostream>
int shift(int *arr, int n, int ele, int i){
    std :: cout << "Hello4\n";
    for(int j = n-1; j > i; j++){
        std :: cout << "Hello5\n";
        arr[j] = arr[j+1];
    }
    arr[i] = ele;
    return 0;
}
int insert(int arr[], int n, int ele, int s, int e){
    std :: cout << "Hello\n";
    int mid = s + (e - s) / 2;
    if(arr[mid] >= ele && arr[mid - 1] <= ele){
        std :: cout << "Hello1\n";
        return shift(arr, n, ele, mid);
    }
    // else if(arr[mid] < ele && arr[mid + 1] >= ele){
    //     return shift(arr, n, ele, mid+1);
    // }
    else if(arr[mid] < ele){
        std :: cout << "Hell02\n";
        return insert(arr, n, ele, mid + 1, e);
    }
    else{
        std :: cout << "Hello3";
        return insert(arr, n, ele, s, mid - 1);
    }
}
 int main(){
    int arr[10] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int ele = 4;
    insert(arr, 10, ele, 0, 9);
    for(int i = 0; i < 10; i++){
        std :: cout << arr[i] << " ";
    }
 }
