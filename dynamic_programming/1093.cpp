#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    
    int sum = n * (n + 1) / 2;

    if (sum & 1) {
        std::cout << 0;
        return 0;
    }

    int hs = sum / 2;

    std::vector<std::vector<int>> dp(n, std::vector<int>(hs + 1));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= hs; s++) {
            dp[i][s] = (dp[i][s] + dp[i - 1][s]) % MOD;
            if (s - i >= 0) {
                dp[i][s] = (dp[i][s] + dp[i - 1][s - i]) % MOD;
            }
        }
    }
    std::cout << dp[n - 1][hs];
    return 0;
}