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

void solve(){
    // code here
    int n, m, k;
    cin >> n >> m >> k;
    multiset<ll> msb, mssa;
    map<ll, ll> ma, mb;
    vector<ll> v(n);
    fl(i, n){
        cin >> v[i];
        if (i < m){
            mssa.insert(v[i]);
            if (ma.find(v[i]) == ma.end()){
                ma[v[i]] = 1;
            }
            else {
                ma[v[i]]++;
            }
        }
    }
    fl(i, m){
        ll x;
        cin >> x;
        msb.insert(x);
        if (mb.find(x) == mb.end()){
            mb[x] = 1;
        }
        else {
            mb[x]++;
        }
    }
    int cnt = 0;
    multiset<ll> temp = msb;
    bool flag = false;
    int t = 0;
    for (auto i: mssa){
        if (temp.find(i) != temp.end()){
            t++;
            temp.erase(temp.find(i));
        }
        if (t >= k and !flag){
            cnt++;
            flag = !flag;
        }
    }
    ll t1 = 0, t2 = m; 
    while (t2 < n){
        mssa.erase(mssa.find(v[t1]));
        ma[v[t1]]--;
        if (mssa.find(v[t1]) == mssa.end() and msb.find(v[t1]) != msb.end()){
            t--;
            if (mssa.find(v[t2]) == mssa.end() and msb.find(v[t2]) != msb.end()){
                t++;
                mssa.insert(v[t2]);
                if (ma.find(v[t2]) == ma.end()){
                    ma[v[t2]] = 1;
                }
                else {
                    ma[v[t2]]++;
                }
            }
            else {
                if (mssa.find(v[t2]) != mssa.end() and msb.find(v[t2]) != msb.end()){
                    if (ma[v[t2]] < mb[v[t2]]){
                        t++;
                    }
                }
                mssa.insert(v[t2]);
                if (ma.find(v[t2]) == ma.end()){
                    ma[v[t2]] = 1;
                }
                else {
                    ma[v[t2]]++;
                }
            }
        }
        else {
            if (mssa.find(v[t1]) != mssa.end() and msb.find(v[t1]) != msb.end()){
                if (ma[v[t1]] < mb[v[t1]]){
                    t--;
                }
            }
            if (mssa.find(v[t2]) == mssa.end() and msb.find(v[t2]) != msb.end()){
                t++;
                mssa.insert(v[t2]);
                if (ma.find(v[t2]) == ma.end()){
                    ma[v[t2]] = 1;
                }
                else {
                    ma[v[t2]]++;
                }
            }
            
            else {
                if (mssa.find(v[t2]) != mssa.end() and msb.find(v[t2]) != msb.end()){
                    if (ma[v[t2]] < mb[v[t2]]){
                        t++;
                    }
                }
                mssa.insert(v[t2]);
                if (ma.find(v[t2]) == ma.end()){
                    ma[v[t2]] = 1;
                }
                else {
                    ma[v[t2]]++;
                }
            }
        }
        if (t >= k) cnt++;
        t1++;
        t2++;
    }
    cout << cnt << en;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    d_n(T);
    while (T--){
        solve();
    }
    return 0;
}