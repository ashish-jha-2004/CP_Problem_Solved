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

typedef long long ll;
typedef vector<ll> vl;

#define fl(i, j) for(int i=0; i<j; i++)
#define all(v) v.begin(), v.end()
#define en "\n"

void solve() {
    ll n;
    scanf("%lld", &n);
    vl v(n);
    ll nn = 0, np = 0, lp = LLONG_MAX;
    fl(i, n) {
        scanf("%lld", &v[i]);
        if (v[i] < 0) nn++;
        else {
            np++;
            lp = min(lp, v[i]);
        }
    }
    sort(all(v));
    ll sum = 0;
    if (nn == n) {

        if (nn % 2 == 1) {
            fl(i, n-1) {
                sum += -v[i];
            }
            sum += v[n-1];
        } else {
            fl(i, n) {
                sum += -v[i];
            }
        }
    } else if (np == n) {
        // All elements are non-negative
        fl(i, n) {
            sum += v[i];
        }
    } else {
        // Mix of negative and non-negative numbers
        if (nn % 2 == 0) {
            // Even number of negatives
            fl(i, n) {
                sum += abs(v[i]);
            }
        } else {
            // Odd number of negatives
            fl(i, nn - 1) {
                sum += -v[i];
            }
            sum += max(v[nn]+v[nn-1], -v[nn]-v[nn - 1]);
            for (int i = nn+1; i < n; i++) {
                sum += v[i];
            }
        }
    }
    printf("%lld\n", sum);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}