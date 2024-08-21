#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i{0}; i<10; i++){
        int x;
        cin >> x;
        p.push(x);
    }
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;

    bitset<10> b(string("1010101010"));
    cout << b[4] << endl;
    cout << b.count() << endl;
    return 0;
}