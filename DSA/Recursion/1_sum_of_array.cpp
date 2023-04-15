#include<iostream>
using namespace std;

int sum_of_array(int arr[], int n){
    if(n == 0)
        return 0;
    return arr[0] + sum_of_array(arr + 1, n - 1);
}
int main(){
    int arr[7] = {5, 3, 2, 5, 7, 4, 2};

    cout << sum_of_array(arr, 7);
    return 0;
}