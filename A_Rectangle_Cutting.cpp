#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long a;
    while (cin >> a){
        long long b;
        cin >> b;
        if ((a%2 != 0 and b%2 != 0) or (a == 1 and b == 1) or (a%2 != 0 and b/2 == a) or (a/2 == b and b%2 != 0)){
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
}