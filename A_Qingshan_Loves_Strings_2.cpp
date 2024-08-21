#include<bits/stdc++.h>
using namespace std;

/*
************************************************************************************************************************************************
    Author :- Ashish Jha
    Yug :- Kaliyug
************************************************************************************************************************************************
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
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define all(v) v.begin(), v.end()
#define d_n(n) ll n; cin >> n
#define d_v(v, n) vl v(n); fl(i, n) cin >> v[i]
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back()
#define MP make_pair
#define B begin()
#define E end()

bool check(string &s){
    fl (i, s.size()){
        if (s[i] == s[s.size()-i-1]) return false;
    }
    return true;
}

bool check1(string s1, string s2){
    reverse(all(s1));
    fl (i, min(s1.size(), s2.size())){
        if (s1[i] == s2[i]) return false;
    }
    return true;
}

void solve(){
    // code here
    d_n(n);
    string s;
    cin >> s;
    // if n is odd
    if (n&1) {
        cout << -1 << en;
        return;
    }
    // if n is equal to 2
    if (n == 2){
        if (s[0] != s[1]){
            cout << 0 << en << en;
            return;
        }
        else {
            cout << -1 << en;
            return;
        }
    }
    // for general case
    ll cnt0 = 0, cnt1 = 0;
    fl (i, n){
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }
    // if cnt0 != cnt1 then it is not possible to make the string good
    if (cnt0 != cnt1) {
        cout << -1 << en;
        return;
    }
    // if cnt0 == cnt1
    vl v;
    deque<ll> dq;
    fl(i, n){
        dq.push_back(s[i]-'0');
    }
    ll i = 0;
    while (!dq.empty()) {
        if (dq.front() != dq.back()) {
            dq.pop_back();
            dq.pop_front();
        }
        else if (dq.front()){
            v.push_back(i);
            dq.pop_back();
            dq.push_front(1);
        }
        else {
            v.push_back(i+dq.size());
            dq.pop_front();
            dq.push_back(0);
        }
        i++;
    }
    cout << v.size() << en;
    for (auto i: v){
        cout << i << " ";
    }
    cout << en;
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