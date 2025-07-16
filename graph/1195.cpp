#include <bits/stdc++.h>

const long long INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::vector<std::array<int, 2>>>> adj(n, std::vector<std::vector<std::array<int, 2>>>(2));
    std::vector<std::array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--; v--;
        adj[u][0].push_back({v, w});
        adj[v][1].push_back({u, w});
        e[i] = {u, v, w};
    }

    auto work = [&](int s, int x) {
        std::vector<long long> dis(n, INF);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> h;
        dis[s] = 0;
        h.push({0, s});
        while (!h.empty()) {
            auto [du, u] = h.top();
            h.pop();
            if (dis[u] < du) {
                continue;
            }
            for (auto [v, w] : adj[u][x]) {
                if (dis[v] > du + w) {
                    dis[v] = du + w;
                    h.push({dis[v], v});
                }
            }
        }
        return dis;
    };

    std::vector<long long> f = work(0, 0);
    std::vector<long long> g = work(n - 1, 1);

    long long res = INF;
    for (auto [u, v, w] : e) {
        res = std::min(res, f[u] + w / 2 + g[v]);
    }

    std::cout << res;
    return 0;
}