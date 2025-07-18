#include <bits/stdc++.h>

const long long INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> h;
    h.push({0, 0});
    std::vector<int> cnt(n, 0);
    while (!h.empty()) {
        auto [du, u] = h.top();
        h.pop();
        if (cnt[u] == k) {
            continue;
        }
        cnt[u]++;
        if (u == n - 1) {
            std::cout << du << " ";
            if (cnt[u] == k) {
                return 0;
            }
        }
        for (auto [v, w] : adj[u]) {
            h.push({du + w, v});
        }
    }
    return 0;
}