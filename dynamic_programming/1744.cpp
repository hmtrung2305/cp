#include <bits/stdc++.h>

const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b;
    std::cin >> a >> b;

    std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1, INF));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 1; k < i; k++) {
                dp[i][j] = std::min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = std::min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            }
        }
    }

    std::cout << dp[a][b];
    return 0;
}