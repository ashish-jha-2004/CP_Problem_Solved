#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int timer = 0;

pair<int,int> find(int ind,vector<vector<int>> &adj,vector<int> &H,int par, map<pair<int,int>,int>& M){
    if(H[ind]!=-1){
        return {H[ind],0};
    }
    timer++;
    H[ind] = timer;
    int res = H[ind],sum = 1;
    for(auto &val:adj[ind]){
        if(val==par) continue;
        pair<int,int> P = find(val,adj,H,ind, M);
        int x = P.first,y = P.second;
        sum+=y;
        if(x<=H[ind]){
            res = min(res,x);
        }
        else{
            M[{ind,val}] = y; 
        }
    }
    H[ind] = res;
    return {res,sum};
}

int main() 
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        map<pair<int,int>,int> M;
        while(m--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        M.clear();
        timer = 0;
        vector<int> H(n,-1);
        pair<int,int> P = find(0,adj,H,-1, M);
        int ans = n*(n-1)/2;
        for(auto &val:M){
            int l = val.second,r = n - val.second;
            ans = min(ans, (l*(l-1) + (r*(r-1)))/2);
        }      
        cout<<ans<<endl;
    }
    return 0;
}
