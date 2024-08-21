#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
	// your code goes here
	for (int i{0}; i<t; i++){
        int n, k;
        cin >> n >> k;
        if (n == k){
            for (int j{1}; j<=k; j++){
                cout << j << " ";
            }
            cout << endl;
        }
        else if (n > k){
            int cnt = 0;int j{n};
            for (; j>=1; j--){
                if (j%(1<<(k-1)) == 0){
                    break;
                }
            }
            int a = j/(1<<(k-1));
            for (int s{1}; s<=pow(2, k-1); s++){
                cout << a*s << " ";
            }
            cout << endl;
        }
	}
}
