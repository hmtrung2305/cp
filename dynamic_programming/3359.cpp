#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<std::vector<int>> p(n, std::vector<int>(n, -1));
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(n));

    std::queue<std::array<int, 2>> q;
    q.push({0, 0});
    for (int i = 0; i < 2 * n - 1; i++) {
        std::vector<std::array<int, 3>> a;
        int min = 26;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 2; d++) {
                int nx = x + d;
                int ny = y + (1 - d);
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {
                    continue;
                }
                vis[nx][ny] = true;
                min = std::min(min, s[nx][ny] - 'A');
                a.push_back({nx, ny, d});
            }
        }
        for (auto [x, y, d] : a) {
            if (min == s[x][y] - 'A') {
                p[x][y] = d;
                q.push({x, y});
            }
        }
    }

    std::string res;
    int x = n - 1, y = n - 1;
    while (x != 0 || y != 0) {
        res += s[x][y];
        int d = p[x][y];
        x -= d;
        y -= 1 - d;
    }
    res += s[0][0];
    reverse(res.begin(), res.end());
    std::cout << res;
    return 0;
}