#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j <= n) {
                dp[i + j] = (dp[i + j] + dp[i]) % MOD;
            }
        }
    }

    std::cout << dp[n];
    return 0;
}