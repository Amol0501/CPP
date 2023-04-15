#include<iostream>
using namespace std;
int union_sort(int* arr1, int n, int* arr2, int m, int* arr){
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else if(arr1[i] > arr2[j])
            arr[k++] = arr2[j++];
        else{
            arr[k++] = arr1[i];
            i++; j++;
        }
    }
}
int main(){
    int n, m;
    cout << "Enter the number of element of 1st sorted array: ";
    cin >> n;
    cout << "Enter the number of element of 2st sorted array: ";
    cin >> m;
    int arr1[n], arr2[m], arr[n + m] = {};
    cout << "Enter the elements of 1st array: ";
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    cout << "Enter te elements of 2st array: ";
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    union_sort(arr1, n, arr2, m, arr);
    
    cout << "The elements in the final array are: ";
    for(int i = 0; i < n+m; i++){
        cout << arr[i] << " ";
    }
    return 0;

}