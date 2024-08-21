#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef vector<ll,ll> vll;
typedef pair<ll,ll> pll;

void solve() {
	int a, b, c, d;
	int x, y, x1, y1, x2, y2;
	cin >> a >> b >> c >> d;
	cin >> x>> y >> x1 >> y1 >> x2 >> y2;
	int x4= x + b - a;
	int y4 = y + d - c;
	if(a + b > 0 && x2 - x1 == 0) {
		cout << "NO\n";
		return;
	}
	if(c+d > 0 && y2 - y1 == 0) {
		cout << "NO\n";
		return;
	}
	if(x1 <= x4 && x4 <= x2 && y1 <= y4 && y4 <= y2) {
		cout << "YES\n";
	} else cout << "NO\n";
}

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	M00(i, t) solve();
}
