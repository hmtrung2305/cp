#include <bits/stdc++.h>

const long long INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    std::vector<long long> dis(n, INF);

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> h;
    dis[0] = 0;
    h.push({0, 0});
    while (!h.empty()) {
        auto [du, u] = h.top();
        h.pop();
        if (dis[u] < du) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dis[v] > du + w) {
                dis[v] = du + w;
                h.push({dis[v], v});
            }
        }
    }

    for (int u = 0; u < n; u++) {
        std::cout << dis[u] << " ";
    }
    return 0;
}