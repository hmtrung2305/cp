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

    int sx = -1, sy = -1;
    int tx = -1, ty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'B') {
                tx = i;
                ty = j;
            }
        }
    }

    std::vector<std::vector<int>> dis(n, std::vector<int>(m, INF));
    std::vector<std::vector<int>> trace(n, std::vector<int>(m, -1));

    std::queue<std::array<int, 2>> q;
    dis[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || 
                s[nx][ny] == '#' || dis[nx][ny] != INF) {
                continue;
            }
            dis[nx][ny] = dis[x][y] + 1;
            trace[nx][ny] = d;
            q.push({nx, ny});
        }
    }

    if (dis[tx][ty] == INF) {
        std::cout << "NO";
        return 0;
    }

    std::cout << "YES" << "\n" << dis[tx][ty] << "\n";
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