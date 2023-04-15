#include<iostream>
#include<stack>
using namespace std;

int postFixEvaluation(string s){
    int ans, opt1, opt2;
    stack<int> st;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }
        else{
            opt1 = st.top();
            st.pop();
            opt2 = st.top();
            st.pop();

            switch (s[i]){
                case '+':
                    st.push(opt1 + opt2);
                    break;
                case '-':
                    st.push(opt2 - opt1);
                    break;
                case '*':
                    st.push(opt1 * opt2);
                    break;
                case '/':
                    st.push(opt2 / opt1);
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}
int main(){
    cout << postFixEvaluation("46+2/5*7+");   
    return 0;
}