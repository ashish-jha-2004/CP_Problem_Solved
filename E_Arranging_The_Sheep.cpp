#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s ;
		cin >> s;
		long low = 0, high = n-1, diff = 0;
		bool first = true;
		for (int i{0}; i<n; ++i) {
			if (first and s[i] == '*') {
				low = i, high = i;
				first = !first;
			}
			else if (s[i] == '*') {
				high = i;
			}
		}
		long optimal = high;
		diff = high - low;
		for (int i{0}; i<n; i++) {
			if (s[i] == '*') {
				if (max(abs(high - (long)i), abs((long)i - low)) <= diff) {
					diff = max(abs(high - (long)i), abs((long)i - low));
					optimal = i;
				}
			}
		}
		long cnt = 0, sum = 0;
		for (int i{optimal-1}; i>=0; i--) {
			if (s[i] == '*') {
				sum += optimal - i - 1 - cnt;
				cnt++;
			}
		}
		cnt = 0;
		for (int i{optimal+1}; i<n; i++) {
			if (s[i] == '*') {
				sum += i - optimal - 1 - cnt;
				cnt++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

