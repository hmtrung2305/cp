#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    if (x[0]) {
        dp[1][x[0]] = 1;
    } else {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (x[i]) {
            for (int k = -1; k <= 1; k++) {
                if (x[i] + k >= 1 && x[i] + k <= m) {
                    dp[i + 1][x[i]] = (dp[i + 1][x[i]] + dp[i][x[i] + k]) % MOD;
                }
            }
        } else {
            for (int j = 1; j <= m; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j + k >= 1 && j + k <= m) {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j + k]) % MOD;
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + dp[n][i]) % MOD;
    }
    std::cout << res;
    return 0;
}