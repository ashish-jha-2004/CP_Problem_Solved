#include<bits/stdc++.h>
// I am the devl of my world 
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define fl(i, j) for(int i{0}; i<j; i++)
#define finl(i, j, k) for(int i{j}; i<k; i++)
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define en "\n"
#define F first
#define S second
#define PB(a) push_back(a)
#define PPB pop_back() 
#define MP make_pair
#define B begin()
#define E end()
#define int long long
#define fl(i, n) for (int i{0}; i<n; i++)

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int Ashish_the_god[n], Anurag_the_god[n];

        fl(i, n){
            cin >> Ashish_the_god[i];
        }
        fl(i, n) {
            cin>>Anurag_the_god[i];
        }
        int sum{0};
        int ans = LLONG_MAX;
        for(int i=n-1; i>=0; i--)
        {
            if(i+1 <= m)
            {
                ans=min(ans,sum+Ashish_the_god[i]);

            }
            sum += min(Ashish_the_god[i],Anurag_the_god[i]);
        }
        cout << ans << "\n";
    }
}