#include<iostream>
using namespace std;

int intersection_sort(int* arr1, int n, int* arr2, int m, int* arr){
    int k = 0;
    int p = 0;
    for(int i = 0; i < n; i ++){
        for(int j = p; j < m; j++){
            if(arr1[i] == arr2[j]){
                arr[k++] = arr1[i];
                p = j;
            }
        }
    }
}
int main(){
    int n, m;
    cout << "Enter the number of element of 1st sorted array: ";
    cin >> n;
    cout << "Enter the number of element of 2st sorted array: ";
    cin >> m;
    int arr1[n], arr2[m], arr[n + m] = {0};
    cout << "Enter te elements of 1st array: ";
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    cout << "Enter te elements of 2st array: ";
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    intersection_sort(arr1, n, arr2, m, arr);
    
    cout << "The elements in the final array are: ";
    for(int i = 0; i < n+m; i++){
        if(arr[i] != 0)
        cout << arr[i] << " ";
    }
    return 0;
}