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

typedef long double ld;
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

int findNumber(vector<pair<int, int>> &a, int n, int K)
{
 
    int low = 0, high = n - 1;
    int ans = -1;
 
    // Binary search
    while (low <= high) {
 
        // Find the mid element
        int mid = (low + high) >> 1;
        
 
        // If element is found
        if (K >= a[mid].first && K <= a[mid].second){
            ans = mid;
            high = mid-1;
        }

 
        // Check in first half
        else if (K < a[mid].first)
            high = mid - 1;
 
        // Check in second half
        else
            low = mid + 1;
    }
 
    // Not found
    return ans;
}

void solve(){
    // code here
    ll n, m, k;
    cin >> n >> m >> k;
    d_v(v, n);
    d_v(v1, m);
    sort(all(v1));
    sort(all(v));
    int cnt = 0, i = 0, j = 0;
    while(i<n and j<m)
	{
		if(v[i]-k>v1[j])j++;
		else if(v[i]+k<v1[j])i++;
		else
		{
			i++,j++,cnt++;
		}
	}
    cout << cnt ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // d_n(t);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}