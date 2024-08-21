#include<iostream>
using namespace std;

int main(){
    int t, a;
    cin >> t;
    while(cin >> a){
        int b;
        cin >> b;
        if ((a%2) == 0 and (b%2) == 0){
            cout << "Bob" << endl;
        }
        else if ((a%2) != 0 and (b%2) != 0){
            cout << "Bob" << endl;
        }
        else {
            cout << "Alice" << endl;
        }
    }
}