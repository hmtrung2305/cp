#include <bits/stdc++.h>

const int INF = 1e9;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char dir[] = {'L', 'R', 'U', 'D'};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::queue<std::array<int, 2>> q;
    int sx = -1, sy = -1;
    std::vector<std::vector<int>> f(n, std::vector<int>(m, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'M') {
                f[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || 
                s[nx][ny] == '#' || f[nx][ny] != INF) {
                continue;
            }
            f[nx][ny] = f[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int tx = -1, ty = -1;
    std::vector<std::vector<int>> g(n, std::vector<int>(m, INF));
    std::vector<std::vector<int>> trace(n, std::vector<int>(m, -1));

    g[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            tx = x;
            ty = y;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || 
                s[nx][ny] == '#' || g[nx][ny] != INF ||
                g[x][y] + 1 >= f[nx][ny]) {
                continue;
            }
            g[nx][ny] = g[x][y] + 1;
            trace[nx][ny] = d;
            q.push({nx, ny});
        }
    }

    if (tx == -1) {
        std::cout << "NO";
        return 0;
    }

    std::cout << "YES" << "\n" << g[tx][ty] << "\n";
    std::string res;
    while (trace[tx][ty] != -1) {
        res += dir[trace[tx][ty]];
        switch (trace[tx][ty]) {
        case 0:
            ty++;;
            break;
        case 1:
            ty--;
            break;
        case 2:
            tx++;
            break;
        default:
            tx--;
            break;
        }
    }
    reverse(res.begin(), res.end());
    std::cout << res;
    return 0;
}