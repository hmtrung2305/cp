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

    std::vector<int> dis(n);
    std::function<void(int)> work = [&](int r) {
        std::function<void(int)> bfs = [&](int s) {
            std::queue<int> q;
            q.push(s);
            dis[s] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!dis[v]) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
            }
        };
        bfs(0);
        r = max_element(dis.begin(), dis.end()) - dis.begin();
        dis.assign(n, 0);
        bfs(r);
    };
    work(0);

    int res = (*max_element(dis.begin(), dis.end())) - 1;
    std::cout << res;
    return 0;
}