#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].size() % 2 == 1) {
            std::cout << "IMPOSSIBLE";
            return 0;
        }
    }

    std::vector<int> res;
    std::vector<bool> vis(m);
    std::function<void(int)> dfs = [&](int u) {
        while (!adj[u].empty()) {
            auto [v, i] = adj[u].back();
            adj[u].pop_back();
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            dfs(v);
        }
        res.push_back(u);
    };
    dfs(0);

    if (res.size() != m + 1) {
        std::cout << "IMPOSSIBLE";
    } else {
        for (int x : res) {
            std::cout << x + 1 << " ";
        }
    }
    return 0;
}