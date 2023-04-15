#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], vector<vector<int>> &ans, vector<int> output, int index){
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(arr, ans, output, index + 1);

    // include 
    output.push_back(arr[index]);
    solve(arr, ans, output, index + 1);
}

int main(){
    int arr[] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    solve(arr, ans, output, 0);
    sort(ans.begin(), ans.end());
    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}