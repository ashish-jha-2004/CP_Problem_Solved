#include <bits/stdc++.h>
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

// Debugging Tools For CP
#ifndef ONLINE_JUDGE
#include "debugtemplate.hpp"
#else
#define debug(...)
#endif

typedef long long ll;
#define d_n(n) ll n; cin >> n
#define d_s(s) string s; cin >> s
#define en "\n"

ll func(string &s, char prev, ll ind) {
    if (ind >= s.size()) {
        return 0;
    }
    
    if (s[ind] == prev) {
        set<char> colors{'R', 'G', 'B'};
        colors.erase(prev);
        if (ind + 1 < s.size()) {
            colors.erase(s[ind + 1]);
        }
        char newColor = *colors.begin();
        s[ind] = newColor;
        
        return 1 + func(s, newColor, ind + 1);
    } 
    else {
        return func(s, s[ind], ind + 1);
    }
}

void solve() {
    d_n(n);
    d_s(s);

    if (n == 1) {
        cout << 0 << en;
        cout << s << en;
        return;
    }

    ll recolorCount = func(s, s[0], 1);

    cout << recolorCount << en;
    cout << s << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}