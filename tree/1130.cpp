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

    std::vector<int> s(n);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        s[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            s[u] &= !s[v];
        }
    };
    dfs(0, -1);

    int res = n - accumulate(s.begin(), s.end(), 0);
    std::cout << res << "\n";
    return 0;
}