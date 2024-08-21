#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/*
****************************************************************************************************************************************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
****************************************************************************************************************************************************************************************************************************************************************************
    मनोबुद्ध्यहङ्कारचित्तानि नाहं न च श्रोत्रजिह्वे न च घ्राणनेत्रे ।
    न च व्योम भूमिर्न तेजो न वायुश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥१॥
    
    न च प्राणसंज्ञो न वै पञ्चवायुर्न वा सप्तधातुर्न वा पञ्चकोशाः ।
    न वाक्पाणिपादं न चोपस्थपायुश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥२॥
    
    न मे द्वेषरागौ न मे लोभमोहौ मदो नैव मे नैव मात्सर्यभावः ।
    न धर्मो न चार्थो न कामो न मोक्षश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥३॥
    
    न पुण्यं न पापं न सौख्यं न दुःखं न मन्त्रो न तीर्थं न वेदा न यज्ञाः ।
    अहं भोजनं नैव भोज्यं न भोक्ता चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥४॥  
    
    न मृत्युर्न शङ्का न मे जातिभेदः पिता नैव मे नैव माता न जन्म ।
    न बन्धुर्न मित्रं गुरुर्नैव शिष्यश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥५॥
    
    अहं निर्विकल्पो निराकाररूपो विभुत्वाञ्च सर्वत्र सर्वेन्द्रियाणाम् ।
    न चासङ्गतं नैव मुक्तिर्न मेयश्चिदानन्दरूपः शिवोऽहं शिवोऽहम् ॥६॥
****************************************************************************************************************************************************************************************************************************************************************************
*/

// Debuging Tools For CP
#ifndef ONLINE_JUDGE
#include "debugtemplate.hpp"
#else
#define debug(...)
#endif
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef pair<ll, ll> pll;
typedef pair<ll, char> plc;
#define fl(i, j) for(int i{0}; i<j; i++)
#define fb(i, j, k) for (int i{j}; i>=k; i--)
#define fn(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define d_n(n) ll n; cin >> n
#define d_s(s) string s; cin >> s
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i]
#define en "\n"
#define F first
#define S second
#define PB push_back
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

// Utility Function
template <class T> 
using ind_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename T>
void pt(T &&t)  { cout << t << "\n"; }
template<typename T>
ll sv(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void display_board(vector<vector<char>> &vc) {
    for (auto &k: vc) {
        for (auto &j: k) {
            cout << j << " ";
        }
        cout << en;
    }
}

bool is_fill(vector<vector<char>> vc) {
    for (auto &k: vc) {
        for (auto &j: k) {
            if (j == '?') return false;
        }
    }
    return true;
}

bool is_win(vector<vector<char>> vc) {
    // horizontal rows
    if ((vc[0][0] == 'O' && vc[0][1] == 'O' && vc[0][2] == 'O') || (vc[0][0] == 'X' && vc[0][1] == 'X' && vc[0][2] == 'X')) return true;
    if ((vc[1][0] == 'O' && vc[1][1] == 'O' && vc[1][2] == 'O') || (vc[1][0] == 'X' && vc[1][1] == 'X' && vc[1][2] == 'X')) return true;
    if ((vc[2][0] == 'O' && vc[2][1] == 'O' && vc[2][2] == 'O') || (vc[2][0] == 'X' && vc[2][1] == 'X' && vc[2][2] == 'X')) return true;

    // vertical rows
    if ((vc[0][0] == 'O' && vc[1][0] == 'O' && vc[2][0] == 'O') || (vc[0][0] == 'X' && vc[1][0] == 'X' && vc[2][0] == 'X')) return true;
    if ((vc[0][1] == 'O' && vc[1][1] == 'O' && vc[2][1] == 'O') || (vc[0][1] == 'X' && vc[1][1] == 'X' && vc[2][1] == 'X')) return true;
    if ((vc[0][2] == 'O' && vc[1][2] == 'O' && vc[2][2] == 'O') || (vc[0][2] == 'X' && vc[1][2] == 'X' && vc[2][2] == 'X')) return true;

    // diagonals
    if ((vc[0][0] == 'O' && vc[1][1] == 'O' && vc[2][2] == 'O') || (vc[0][0] == 'X' && vc[1][1] == 'X' && vc[2][2] == 'X')) return true;
    if ((vc[0][2] == 'O' && vc[1][1] == 'O' && vc[2][0] == 'O') || (vc[0][2] == 'X' && vc[1][1] == 'X' && vc[2][0] == 'X')) return true;

    return false;
}


void solve(){
    // code here
    vector<vector<char>> vc(3, vector<char>(3, '?'));
    display_board(vc);
    cout << "Hello buddy welcome to Game Arena \n";
    cout << "Enter the name of player 1 : \n";
    d_s(p1);
    cout << "Enter the name of player 2 : \n";
    d_s(p2);
    map<int, pair<int, int>> mp;
    mp[7] = {0, 0}; mp[8] = {0, 1}; mp[9] = {0, 2};
    mp[4] = {1, 0}; mp[5] = {1, 1}; mp[6] = {1, 2};
    mp[1] = {2, 0}; mp[2] = {2, 1}; mp[3] = {2, 2};
    bool flag = true;
    while (true) {
        cout << "where you want to fill \n";
        d_n(pos);
        auto [t1, t2] = mp[pos];
        if (flag and vc[t1][t2] == '?') vc[t1][t2] = 'X';
        else if (!flag and vc[t1][t2] == '?') vc[t1][t2] == 'O';
        display_board(vc);
        if (is_fill(vc)) {
            flag = !flag;
            break;
        }
        else if (is_win(vc)) {
            if (flag) cout << p1 << " wins the game !! \n";
            else cout << p2 << " wins the game !! \n";
            // display_board(vc);
            break;
        }
        flag = !flag;
    }
}

int main(){
    solve();
    return 0;
}