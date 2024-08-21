#include <bits/stdc++.h>
    
using namespace std;
    
#define all(x) (x).begin(), (x).end()
#define endl "\n"
    
using ll = long long;
    
template <typename T>
using pr = pair<T, T>;
    
template <typename T>
using vc = vector<T>;
    
template <typename T>
using vv = vector<vector<T>>;
    
constexpr int MOD = 1e9+7;
    
char grid[3][3];
bool used[3][3];
    
string ans = "ZZZ";
void lex_small(int x, int y, string curr) {
    if(curr.size() == 3) {
        if(curr < ans) ans = curr;
        return;
    }
    
    char smallest = 'Z';
    if(x == -1 && y == -1) {
        for(int i = 0; i<3; ++i) {
            for(int j = 0; j<3; ++j) {
                if(grid[i][j] < smallest && !used[i][j]) {
                    smallest = grid[i][j];
                }
            }
        }
    } else {
        if(x-1 >= 0) if(grid[x-1][y] < smallest && !used[x-1][y]) {
                smallest = grid[x-1][y];
            }
        if(x+1 < 3) if(grid[x+1][y] < smallest && !used[x+1][y]) {
                smallest = grid[x+1][y];
            }
        if(y-1 >= 0) if(grid[x][y-1] < smallest && !used[x][y-1]) {
                smallest = grid[x][y-1];
            }
        if(y+1 < 3) if(grid[x][y+1] < smallest && !used[x][y+1]) {
                smallest = grid[x][y+1];
            }
        if(x-1 >= 0 && y-1 >= 0) if(grid[x-1][y-1] < smallest && !used[x-1][y-1]) {
                smallest = grid[x-1][y-1];
            }
        if(x-1 >= 0 && y+1 < 3) if(grid[x-1][y+1] < smallest && !used[x-1][y+1]) {
                smallest = grid[x-1][y+1];
            }
        if(x+1 < 3 && y-1 >= 0) if(grid[x+1][y-1] < smallest && !used[x+1][y-1]) {
                smallest = grid[x+1][y-1];
            }
        if(x+1 < 3 && y+1 < 3) if(grid[x+1][y+1] < smallest && !used[x+1][y+1]) {
                smallest = grid[x+1][y+1];
            }
    }
    
    if(x == -1 && y == -1) {
        for(int i = 0; i<3; ++i) {
            for(int j = 0; j<3; ++j) {
                if(grid[i][j] == smallest && !used[i][j]) {
                    used[i][j] = true;
                    lex_small(i, j, curr + grid[i][j]);
                    used[i][j] = false;
                }
            }
        }
    } else {
        if(x-1 >= 0) if(grid[x-1][y] == smallest && !used[x-1][y]) {
                used[x-1][y] = true;
                lex_small(x-1, y, curr + grid[x-1][y]);
                used[x-1][y] = false;
            }
        if(x+1 < 3) if(grid[x+1][y] == smallest && !used[x+1][y]) {
                used[x+1][y] = true;
                lex_small(x+1, y, curr + grid[x+1][y]);
                used[x+1][y] = false;
            }
        if(y-1 >= 0) if(grid[x][y-1] == smallest && !used[x][y-1]) {
                used[x][y-1] = true;
                lex_small(x, y-1, curr + grid[x][y-1]);
                used[x][y-1] = false;
            }
        if(y+1 < 3) if(grid[x][y+1] == smallest && !used[x][y+1]) {
                used[x][y+1] = true;
                lex_small(x, y+1, curr + grid[x][y+1]);
                used[x][y+1] = false;
            }
        if(x-1 >= 0 && y-1 >= 0) if(grid[x-1][y-1] == smallest && !used[x-1][y-1]) {
                used[x-1][y-1] = true;
                lex_small(x-1, y-1, curr + grid[x-1][y-1]);
                used[x-1][y-1] = false;
            }
        if(x-1 >= 0 && y+1 < 3) if(grid[x-1][y+1] == smallest && !used[x-1][y+1]) {
                used[x-1][y+1] = true;
                lex_small(x-1, y+1, curr + grid[x-1][y+1]);
                used[x-1][y+1] = false;
            }
        if(x+1 < 3 && y-1 >= 0) if(grid[x+1][y-1] == smallest && !used[x+1][y-1]) {
                used[x+1][y-1] = true;
                lex_small(x+1, y-1, curr + grid[x+1][y-1]);
                used[x+1][y-1] = false;
            }
        if(x+1 < 3 && y+1 < 3) if(grid[x+1][y+1] == smallest && !used[x+1][y+1]) {
                used[x+1][y+1] = true;
                lex_small(x+1, y+1, curr + grid[x+1][y+1]);
                used[x+1][y+1] = false;
            }
    }
}
    
void solve()
{
    for(int i = 0; i<3; ++i) {
        for(int j = 0; j<3; ++j) {
            cin >> grid[i][j];
            used[i][j] = false;
        }
    }
    
    lex_small(-1, -1, "");
    
    cout << ans << endl;
    
}
    
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    return 0;
}