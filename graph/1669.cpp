#include <bits/stdc++.h>

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
        adj[v].push_back(u);
    }

    std::vector<int> res;

    std::vector<int> stk{n};
    std::vector<int> siz(n);
    std::function<bool(int, int)> dfs = [&](int u, int p) {
        siz[u] = stk.size();
        stk.push_back(u);
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            int x = siz[v];
            if (x > 0) {
                stk.push_back(v);
                res = std::vector<int>(stk.begin() + x, stk.end());
                return true;
            }
            if (dfs(v, u)) {
                return true;
            }
        }
        stk.pop_back();
        return false;
    };

    for (int u = 0; u < n; u++) {
        if (siz[u]) {
            continue;
        }
        if (dfs(u, -1)) {
            std::cout << res.size() << "\n";
            for (int i = 0; i < (int)res.size(); i++) {
                std::cout << res[i] + 1 << " ";
            }
            return 0;
        }
    }

    std::cout << "IMPOSSIBLE";
    return 0;
}