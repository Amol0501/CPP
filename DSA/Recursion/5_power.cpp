#include<iostream>
using namespace std;

// int power(int a, int b){
//     // cout << "HEllo ";
//     if(b == 0){
//         return 1;
//     }
//     return a*power(a, b - 1);
// }
// int main(){
//     cout << power(2, 20);
//     return 0;
// }


// second approach -------

int power(int a, int b){
    // cout << "Hello ";
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    int ans = power(a, b/2);
    if(b % 2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
}

int main(){
    cout << power(2, 30);
    return 0;
}