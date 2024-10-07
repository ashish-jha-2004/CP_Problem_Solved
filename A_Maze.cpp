#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 500;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m, k;
int emptyCells = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    if (emptyCells == k) return;
    visited[x][y] = true;
    emptyCells--;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {

    cin >> n >> m >> k;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                emptyCells++;
            }
        }
    }
    
    bool foundStart = false;
    for (int i = 0; i < n && !foundStart; ++i) {
        for (int j = 0; j < m && !foundStart; ++j) {
            if (maze[i][j] == '.') {
                dfs(i, j);
                foundStart = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == '.' && !visited[i][j]) {
                maze[i][j] = 'X';
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
