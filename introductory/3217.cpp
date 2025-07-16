#include <bits/stdc++.h>

constexpr int INF = 1e9;

const int dx[] = {2, 1, 1, 2, -2, -1, -1, -2};
const int dy[] = {1, 2, -2, -1, 1, 2, -2, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> res(n, std::vector<int>(n, INF));
    res[0][0] = 0;

    std::queue<std::array<int, 2>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx < 0 || nx >= n || ny >= n || res[nx][ny] != INF) {
                continue;
            }
            res[nx][ny] = res[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << res[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}