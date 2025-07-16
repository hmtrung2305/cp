#include <bits/stdc++.h>

const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j]) {
                dp[i] = std::min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }

    std::cout << (dp[x] == INF ? -1 : dp[x]);
    return 0;
}