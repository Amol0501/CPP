#include<iostream>
// using namespace std;
int b_search(int arr[10], int n, int num){
    int s = 0;
    int e = n - 1;
    int mid;
    while(s <= e){
        mid = s + (e - s) / 2;
        if(num == arr[mid])
            return mid;
        else if(num < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main(){
    int length = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = 10;
    std :: cout << b_search(arr, length, num);
    return 0;
}