#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
************************************************************************************************************************************************
    ॐ त्र्यम्बकं यजामहे
    सुगन्धिं पुष्टिवर्धनम् ।
    उर्वारुकमिव बन्धनान्
    मृत्योर्मुक्षीय मामृतात् ॥
************************************************************************************************************************************************
*/

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define sortall(v) sort(v.begin(), v.end())
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i];
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

int mostFrequent(vl &arr, int n) 
{ 
    // Insert all elements in hash. 
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    // find the max frequency 
    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return res; 
} 

int minDist(vector<ll> &a, int n)
{ 

	map<int,int> hmap;

	int minDistance = INT_MAX; 
	int previousIndex = 0, currentIndex = 0; 

	for (int i = 0; i < n; i++) { 

		if (hmap.find(a[i])!=hmap.end()) { 
			currentIndex = i; 
			previousIndex = hmap[a[i]];  
			minDistance = min((currentIndex - previousIndex),minDistance); 
		} 

		hmap[a[i]] = i; 
	} 

	return (minDistance == INT_MAX ? -1 : minDistance); 
}

bool cmp(int x, int y){
    return (x < y);
}

void solve(){
    // code here
    ll n;
    cin >> n;
    vl v(n, 0);
    map<ll, ll> m;
    fl(i, n){
        cin >> v[i];
        m[v[i]] = 0;
    }
    if (m.size() <= 1){
        cout << -1 << en;
        return;
    }
    ll mf = mostFrequent(v, n);
    // cerr << mf << en;
    map<ll, ll> mp;
    mp[1] = 0;
    mp[0] = 0;
    int a = 1;
    fl(i, n){
        if (v[i] == mf){
            v[i] = a;
            mp[v[i]]++;
            a++;
        }
        else {
            v[i] = 0;
            mp[v[i]]++;
        }
    }
    // cerr << mp[0] << en;
    if (mp[0] == 1){
        int ans1, ans2;
        fl(i, n){
            if (v[i] == 0){
                ans1 = i;
                break;
            }
        }
        for (int i{n-1}; i>=0; i--){
            if (v[i] == 0){
                ans2 = n-i-1;
                break;
            }
        }
        cout << min(ans1, ans2) << en;
        return;
    }
    else {
        int ans1, ans2, ans3;
        fl(i, n){
            if (v[i] == 0){
                ans1 = i;
                break;
            }
        }
        for (int i{n-1}; i>=0; i--){
            if (v[i] == 0){
                ans2 = n-i-1;
                break;
            }
        }
        ans3 = minDist(v, n) - 1;
        cout << min({ans1, ans2, ans3}, cmp) << en;
        return;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(t);
    while (t--){
        solve();
    }
    return 0;
}