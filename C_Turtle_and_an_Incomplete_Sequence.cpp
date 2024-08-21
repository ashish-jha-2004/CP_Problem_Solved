#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int T, n, a[200005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            flag &= a[i] == -1;
        }
        if (flag) {
            for (int i = 1; i <= n; i++) 
                printf("%d ", i & 1 ? 1 : 2);
            puts("");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != -1) {
                int r = i + 1;
                while (r <= n && a[r] == -1) r++;
                if (r > n) break;
                vector<int> vl, vr;
                int flag = 0;
                for (int j = 26; j >= 0; j--) {
                    if (a[i] >> j & 1 or flag) {
                        vl.push_back(a[i] >> j & 1);
                        flag = 1;
                    }
                }
                flag = 0;
                for (int j = 26; j >= 0; j--) {
                    if (a[r] >> j & 1 or flag) {
                        vr.push_back(a[r] >> j & 1);
                        flag = 1;
                    }
                }
                int pos = 0;
                while (pos < (int)min(vl.size(), vr.size()) && vl[pos] == vr[pos])
                    pos++;
                // eprintf("%d\n", pos);
                int x = a[i];
                for (int j = i + 1; j < r; j++) {
                    // eprintf("%d %d\n", x, __lg(x));
                    if (__lg(x) + 1 > pos) x >>= 1;
                    else if (pos < (int)vr.size()) x = x << 1 | vr[pos++];
                    else if (x == a[r]) x <<= 1;
                    else x >>= 1;
                    a[j] = x;
                }
                if (a[r - 1] / 2 != a[r] && a[r] / 2 != a[r - 1]) {
                    puts("-1");
                    goto NXT;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != -1) {
                for (int j = i - 1; j >= 1; j--)
                    if (a[j + 1] == a[i]) a[j] = a[i] * 2;
                    else a[j] = a[i];
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] != -1) {
                for (int j = i + 1; j <= n; j++)
                    if (a[j - 1] == a[i]) a[j] = a[i] * 2;
                    else a[j] = a[i];
                break;
            }
        }
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        puts("");
        NXT:;
    }
    return 0;
}