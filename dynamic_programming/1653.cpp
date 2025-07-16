#include <bits/stdc++.h>

const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::vector<int> f(1 << n, INF), g(1 << n, INF);
    f[0] = 1;
    g[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (g[mask ^ (1 << i)] + w[i] > x) {
                if (f[mask] >= f[mask ^ (1 << i)] + 1) {
                    f[mask] = f[mask ^ (1 << i)] + 1;
                    g[mask] = std::min(g[mask], w[i]);
                }
            } else {
                f[mask] = f[mask ^ (1 << i)];
                g[mask] = std::min(g[mask], g[mask ^ (1 << i)] + w[i]);
            }
        }
    }

    std::cout << f[(1 << n) - 1];
    return 0;
}