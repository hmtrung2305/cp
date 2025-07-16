#include <bits/stdc++.h>

const int INF = 1e9;

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

    std::vector<int> trace(n, -1);
    std::vector<int> dis(n, INF);

    std::queue<int> q;
    q.push(0);
    dis[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dis[v] != INF) {
                continue;
            }
            dis[v] = dis[u] + 1;
            trace[v] = u;
            q.push(v);
        }
    }

    if (dis[n - 1] == INF) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }

    std::cout << dis[n - 1] + 1 << "\n";
    std::vector<int> res;
    int x = n - 1;
    while (x != 0) {
        res.push_back(x);
        x = trace[x];
    }
    res.push_back(0);
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] + 1 << " ";
    }
    return 0;
}