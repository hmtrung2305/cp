#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        p--;

        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    std::vector<int> s(n);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        s[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            s[u] += s[v];
        }
    };
    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        std::cout << s[i] - 1 << " ";
    }
    return 0;
}