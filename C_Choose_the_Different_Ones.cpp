#include <iostream>
#include<vector>
#include<string>
using namespace std;

// I am the devil of my world
int main(){
    int t;
    cin >> t;
    int n;
    while(cin >> n)
    {
        int m,A,B,k;
        int common = 0;
        cin >> m >> k;
        A = B = k/2;
        vector<int> iterate_in_a(k),iterate_in_b(k), a(n), b(m);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] <= k) iterate_in_a[a[i]-1]++;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
            if(b[i] <= k) iterate_in_b[b[i]-1]++;
        }
        for(int i = 0; i < k; i++)
        {
            if(iterate_in_b[i] && !iterate_in_a[i] && B)
            {
                B--;
            }
            else if(!iterate_in_b[i] && iterate_in_a[i] && A)
            {
                A--;
            }
            else if(iterate_in_b[i] && iterate_in_a[i])
            {
                common++;
            }
        }
        if(A+B-common == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}