#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int dub = 0;
    for(int i = 0; i < n - 1; i++){
        int count = 0;
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                dub = arr[i];
                count++;
                i++;
            }
        }
        if(count > 0){
            cout << "\nDublicate number is: " << dub << "   And Count is: " << count + 1;
        }
    }
    return 0;
}