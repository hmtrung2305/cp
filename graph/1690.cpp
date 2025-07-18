#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int N = 20;

int cnt[1 << N][N];
bool vis[1 << N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    cnt[1][0] = 1;
    vis[1][0] = true;
    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto [mask, u] = q.front();
        q.pop();
        if (u == n - 1) {
            continue;
        }
        for (int v : adj[u]) {
            if ((mask & (1 << v)) > 0) {
                continue;
            }
            cnt[mask | (1 << v)][v] = (cnt[mask | (1 << v)][v] + cnt[mask][u]) % MOD;
            if (vis[mask | (1 << v)][v]) {
                continue;
            }
            vis[mask | (1 << v)][v] = true;
            q.push({mask | (1 << v), v});
        }
    }

    std::cout << cnt[(1 << n) - 1][n - 1];
    return 0;
}