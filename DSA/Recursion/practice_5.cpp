// nCr

#include<iostream>
// using namespace std;
int fac(int n){
    if(n == 0)
        return 1;
    else
        return fac(n -1) * n;
}

int main(){
    int n, r;
    std::cin >> n >> r;
    std::cout << fac(n)/(fac(r) * fac(n-r));
    return 0;
}