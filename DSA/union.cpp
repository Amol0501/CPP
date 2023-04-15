#include<iostream>
using namespace std;
int union_sort( int* arr1, int n, int* arr2, int m, int* arr){
    bool frag = true;
    int k = n;
    for(int i = 0; i < n; i++){
        arr[i] = arr1[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr2[i] == arr1[j]){
                frag = false;
                break;
            }
            else{
                frag = true;
            }
        }
        if(frag == true)
            arr[k++] = arr2[i];
        else
            continue;
    }
}
int main(){
    int n, m;
    cout << "Enter the number of element of 1st unsorted array: ";
    cin >> n;
    cout << "Enter the number of element of 2st unsorted array: ";
    cin >> m;
    int arr1[n], arr2[m], arr[n + m] = {0};
    cout << "Enter the elements of 1st array: ";
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    cout << "Enter the elements of 2st array: ";
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    
    union_sort(arr1, n, arr2, m, arr);
    
    cout << "The elements in the final array are: ";
    for(int i = 0; i < n+m; i++){
        if(arr[i] != 0)
            cout << arr[i] << " ";
    }
    return 0;

}