#include <bits/stdc++.h>

const long long INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<long long>> g(n, std::vector<long long>(n, INF));
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        a--; b--;
        g[a][b] = std::min(g[a][b], c);
        g[b][a] = std::min(g[b][a], c);
    }

    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                    g[j][i] = g[i][k] + g[k][j];
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        std::cout << (g[a][b] == INF ? -1 : g[a][b]) << "\n";
    }


    return 0;
}