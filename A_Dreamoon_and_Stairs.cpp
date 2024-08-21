#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll s, t;
    cin >> s >> t;
    ll m, n, r = 0;
    if (s < t)
    {
        cout << -1;
    }
    else if (s == t)
    {
        cout << t;
    }
    else
    {
        m = s / 2;
        n = s - (2 * m);
        while (m >= 0)
        {
            if ((m + n) % t != 0)
            {
                m--;
                n += 2;
                r = 0;
            }
            else
            {
                r = 1;
                break;
            }
        }
        if (r == 1)
        {
            cout << (m + n);
        }
        else
        {
            cout << -1;
        }
    }
    return 0;
}