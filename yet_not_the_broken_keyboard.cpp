#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

void new_stack_B(stack<char> &st) {
    if (st.empty()) {
        return;
    }
    if (st.top() <= 90 and st.top() >= 65) {
        st.pop();
        return;
    }
    char temp = st.top();
    st.pop();  // Remove the top element before the recursive call
    new_stack_B(st);
    st.push(temp);
}

void new_stack_b(stack<char> &st) {
    if (st.empty()) {
        return;
    }
    if (st.top() >= 97 and st.top() <= 122) {
        st.pop();
        return;
    }
    char temp = st.top();
    st.pop();  // Remove the top element before the recursive call
    new_stack_b(st);
    st.push(temp);
}

void print(stack<char> &st) {
    if (st.empty()){
        return;
    }
    char temp = st.top();
    st.pop();
    print(st);
    cout << temp ;
}

void solve(string &n) {
    stack<char> st;
    for (int i = 0; i < n.length(); i++) {
        char temp = n[i];
        if (temp == 'B' || temp == 'b') {
            if (!st.empty() and temp == 'B') {
                new_stack_B(st);
            } else if (!st.empty() and temp == 'b') {
                new_stack_b(st);
            }
        } else {
            st.push(temp);
        }
    }
    print(st);
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;
        solve(n);
    }
    return 0;
}
