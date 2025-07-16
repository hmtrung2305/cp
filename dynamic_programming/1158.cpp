#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(x + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= h[i - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
            }
        }
    }

    std::cout << dp[n][x];
    return 0;
}