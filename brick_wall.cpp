#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long int n;
    while (cin >> n){
        long long int m;
        cin >> m;
        int uttar = n*(m/2);
        cout << uttar << endl;
    }
}