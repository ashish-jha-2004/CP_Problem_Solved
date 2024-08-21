#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    int a;
    while(cin >> a){
        int b;        
        cin >> b;
        if (a == 1){
            cout << b*b <<endl;
        }
        else if(b%2 == 0 || a%2 == 0){
            cout << b*2 << endl;
        }
        else {
            int ans = a;
            for (int i{3}; i<=(sqrt(b)/1)+1; i+=2){
                if (a%i == 0 || b%i == 0){
                    ans = i;
                    break;
                }
            }
            cout << ans*b << endl;
        }
    }
}