// Sum of n natural number

#include<iostream>
using namespace std;
int sum_of_n_numbers(int n){
    if(n > 0){
        return sum_of_n_numbers(n-1) + n;
    }
    
}

int main(){
    int n, sum;
    cin >> n;
    sum = sum_of_n_numbers(n);
    cout << sum;
    return 0;
}