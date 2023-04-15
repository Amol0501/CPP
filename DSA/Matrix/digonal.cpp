// #include<iostream>
// using namespace std;
// struct matrix{
//     int a[10];
//     int n;
// };

// void set(struct matrix *m, int i, int j, int x){
//     if(i == j)
//         m->a[i-1] = x;
// }

// int get(struct matrix m, int i, int j){
//     if(i == j)
//         return m.a[i-1];
//     else
//         return 0;
// }

// void display(struct matrix m){
//     for(int i = 0; i < m.n; i++){
//         for(int j = 0; j < m.n; j++){
//             if(i == j)
//                 cout << m.a[i] << " ";
//             else
//                 cout << 0 << " ";
//         }
//         cout << endl;
//     }
// }

// int main(){
//     struct matrix m;
//     m.n = 5;

//     set(&m, 1, 1, 5);
//     set(&m, 2, 2, 8);
//     set(&m, 3, 3, 10);
//     set(&m, 4, 4, 2);
//     set(&m, 5, 5, 4);

//     // cout << get(m);
//     display(m);
    
//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int t;
// 	cin >> t;
// 	while(t--){
// 	    int n;
// 	    cin >> n;
// 	    int arr[n], arr2[n];
// 	    int count = 0;
// 	    arr[0] = 0, arr2[0] = 0;
// 	    for (int i = 1; i < n+1; i++){
// 	        cin >> arr[i];
// 	        arr[i] = arr[i] - arr[i-1];
// 	    }
// 	    for (int i = 1; i < n+1; i++)
// 	        cin >> arr2[i];
	        
// 	    for (int i = 1; i < n+1; i++){
// 	        if(arr[i] >= arr2[i]){
// 	            count++;
// 	        }
// 	    }
// 	    cout << count << endl;
// 	}
// 	return 0;
// }





#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        // string s = to_string(n);
        // char arr[] = {s};
        // int count = 0;
        // for( int i = 0; i < s.length(); i++){
        //     if(arr[i] == 49){
        //         count++;
        //     }
        // }
        // return count;
        
        // map<char, int> m;
        // cout << s.length() << " ";
        // for(int i = 0; i < 32; i++){
        //     m[s[i]]++;
        // }
        // return m['1'];
        // int n2 = n;
        int count  = 0;
        while(n > 0){
            if(n%10 == 1){
                count++;
                cout << "keng ";
            }
            n /= 10;
            cout << "ksnfffg ";
        }
        return count;
    }
};

int main(){
    Solution s1;
    int n;
    cin >> n;
    cout << s1.hammingWeight(n);
    return 0;
}