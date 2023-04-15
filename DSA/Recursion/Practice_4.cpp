// fibonacci series
#include<iostream>
// using namespace std;

int fib(int n){
    if(n <= 1)
        return n;
    else
        std::cout << n << "\n";
        return fib(n - 2) + fib(n - 1);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << fib(n);    
    return 0;
}