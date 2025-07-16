#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::array<int, 2>> f(n), g(n);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            g[u] = std::max(g[u], {f[v][0] + 1, v});
            if (g[u] > f[u]) {
                std::swap(g[u], f[u]);
            }
        }
    };
    dfs(0, -1);

    std::vector<int> res(n);
    std::function<void(int, int, int)> reroot = [&](int u, int p, int d) {
        res[u] = std::max(f[u][0], d);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (v == f[u][1]) {
                reroot(v, u, 1 + std::max(g[u][0], d));
            } else {
                reroot(v, u, 1 + res[u]);
            }
        }
    };
    reroot(0, -1, 0);

    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " ";
    }
    return 0;
}