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

    std::vector<int> c(n);

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            c[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (c[v] == c[u]) {
                        std::cout << "IMPOSSIBLE";
                        return 0;
                    }
                    if (c[v] != 0) {
                        continue;
                    }
                    c[v] = 3 - c[u];
                    q.push(v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << c[i] << " ";
    }
    return 0;
}