#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    dp[0][0] = (s[0][0] == '.');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) || s[i][j] == '*') {
                continue;
            }
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    std::cout << dp[n - 1][n - 1];
    return 0;
}