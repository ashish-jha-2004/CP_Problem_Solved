#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
typedef vector<pair<int, int>> vpi;
#define int long long
#define fn(i, k, j) for(int i{k}; i<j; i++)
const int INF=LLONG_MAX;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vpi vp(n);
        int maxi=0;
        
        for (int i = 0; i < n; i++)
        {
            cin >> vp[i].F >> vp[i].S;
            maxi+=vp[i].S;
        }
        int Ashish_Jha[n+1][maxi+1];
        fn(i, 0, n+1)
        {
            for(int j=0;j<=maxi;j++)
            {
                Ashish_Jha[i][j]=LLONG_MIN;
            }
        }
        
        
        

        Ashish_Jha[1][0]=x;
        if(vp[0].F==0)
        {
            Ashish_Jha[1][vp[0].S]=x;
        }
        fn(i, 2, n+1)
        {
            fn(j, 0, maxi+1)
            {
                Ashish_Jha[i][j]=Ashish_Jha[i-1][j]+x;
                if(j>=vp[i-1].S)
                {
                    int prev_hap=j-vp[i-1].S;
                    int prev_left=Ashish_Jha[i-1][prev_hap];
                    if(prev_left>=vp[i-1].F)
                    {
                        Ashish_Jha[i][j]=max(Ashish_Jha[i][j],prev_left-vp[i-1].F+x);
                    }
                }

            }
        }
        int ans=0;
        for(int i=maxi;i>=0;i--)
        {
            if(Ashish_Jha[n][i]>=0)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
        
    }
}