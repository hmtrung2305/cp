#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> in(n), out(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        out[u]++;
        in[v]++;
    }

    if (out[0] != in[0] + 1 || out[n - 1] != in[n - 1] - 1) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i < n - 1; i++) {
        if (in[i] != out[i]) {
            std::cout << "IMPOSSIBLE";
            return 0;
        }
    }

    std::vector<int> res;
    std::function<void(int)> dfs = [&](int u) {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v);
        }
        res.push_back(u);
    };
    dfs(0);

    if (res.size() != m + 1) {
        std::cout << "IMPOSSIBLE";
    } else {
        reverse(res.begin(), res.end());
        for (int x : res) {
            std::cout << x + 1 << " ";
        }
    }
    return 0;
}