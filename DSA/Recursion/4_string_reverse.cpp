#include<iostream>
using namespace std;

void string_reverse(string &st, int s, int e){
    if(s > e){
        return;
    }
    swap(st[s], st[e]);
    string_reverse(st, s + 1, e - 1);
}
int main(){
    string st = "Amol";
    string_reverse(st, 0, st.size() - 1);
    cout << st;
    return 0;
}