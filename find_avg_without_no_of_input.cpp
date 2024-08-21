#include<iostream>
using namespace std;

int main(){
    int val;
    int cnt = 0, va = 0;
    while(cin >> val){
        cnt++;
        va += val;
    }
    cout << va/cnt << endl;
}