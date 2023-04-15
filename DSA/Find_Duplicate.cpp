#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int dub;
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                dub = arr[i];
                if(dub == arr[i+1]){
                    i++;
                }
            }
        }
        if(dub != 0)
            cout << dub << "\n"; 
    }
    return 0;
}