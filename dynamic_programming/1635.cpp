#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    std::vector<int> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j]) {
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }

    std::cout << dp[x];
    return 0;
}