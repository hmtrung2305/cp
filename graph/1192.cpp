#include <bits/stdc++.h>

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int res = 0;

    std::queue<std::array<int, 2>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                continue;
            }
            res++;
            s[i][j] = '#';
            q.push({i, j});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#'){
                        continue;
                    }
                    s[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }

    std::cout << res;
    return 0;
}