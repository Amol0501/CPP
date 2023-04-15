#include<iostream>
// using namespace std;
int TOH(int n, int A, int B, int C){
    if(n > 0){
        TOH(n-1, A, C, B);
        std::cout << "(" << A << " " << C << ")" << "\n";
        TOH(n-1, B, A, C);
    }
}
int main(){
    int n;
    std::cin >> n;
    TOH(n, 1, 2, 3);
    return 0;
}