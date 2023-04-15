#include<iostream>
int merge(int* arr, int l , int mid, int r){
    int i = 0;
    int j = 0;
    int n = 0;
    int n1 = mid - l - 1;
    int n2 = r - mid;
    int arr1[n1], arr2[n2];
    
    for(int k = 0; k < n1; k++){
        arr1[k] = arr[l+i];
        // std::cout<< arr1[k] <<"hello\n";
    }
    for(int k = 0; k < n2; k++){
        arr2[k] = arr[mid + i + 1];
    }
    while(i < 5 && j < 4){
        if(arr1[i] <= arr2[j])
            arr[n++] = arr1[i++];
        else
            arr[n++] = arr2[j++];
    }
    while(i < 5){
        arr[n++] = arr1[i++];
    }
    while(j < 4){
        arr[n++] = arr2[j++];
    }
}
int merge_sort(int* arr, int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        merge_sort(arr , l , mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

}
int main(){
    int arr[10] = {1, 3, 5, 2, 7 , 4, 8, 5, 20, 2};
    int l = 0, r = 9;
    merge_sort(arr, l, r);
    for(int i = 0; i < 9; i++){
        std :: cout << arr[i] << "\n";
        
    }
}