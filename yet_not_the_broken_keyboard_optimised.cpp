#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

void solve(string &n) {
    stack<char> upper;
    stack<char> lower;
    vector<char> v;
    for (long long i{0}; i<n.length(); i++){
        v.push_back(n[i]);
        if (!upper.empty() and n[i] == 'B' and upper.top() <= 90){
            upper.pop();
        }
        else if (!lower.empty() and n[i] == 'b' and lower.top() >= 97){
            lower.pop();
        }
        else if (n[i] <= 90 and n[i] != 'B'){
            upper.push(n[i]);
        }
        else if (n[i] >= 97 and n[i] != 'b'){
            lower.push(n[i]);
        }
    }
    stack<char> new_upper;
    stack<char> new_lower;
    while (!upper.empty() or !lower.empty()){
        if (!upper.empty()){
            new_upper.push(upper.top());
            upper.pop();
        }
        if (!lower.empty()){
            new_lower.push(lower.top());
            lower.pop();
        }
    }
    long long i = 0;
    while(!new_upper.empty() or !new_lower.empty()){
        if (i < v.size()){
            if (!new_upper.empty() and !new_lower.empty()){
                if (v[i] == new_upper.top() or v[i] == new_lower.top()){
                    if (v[i] == new_upper.top()){
                        cout << new_upper.top();
                        new_upper.pop();
                    }
                    if (v[i] == new_lower.top()){
                        cout << new_lower.top();
                        new_lower.pop();
                    }
                    i++;
                }
                else{
                    long long j = i;
                    while (v[j] == new_upper.top() or v[j] == new_lower.top()){
                        j++;
                    }
                    i = j;
                }
            }
            else if (!new_upper.empty()){
                while(!new_upper.empty()){
                    cout << new_upper.top();
                    new_upper.pop();
                }
            }
            else if (!new_lower.empty()){
                while(!new_lower.empty()){
                    cout << new_lower.top();
                    new_lower.pop();
                }
            }
        }
        else{
            break;
        }
    } 
    cout << endl;
} 

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string n;
        getline(cin, n);
        solve(n);
    }
    return 0;
}
