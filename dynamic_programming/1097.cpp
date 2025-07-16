#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n));
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            if (l == r) {
                dp[l][r] = x[l];
                continue;
            }
            dp[l][r] = std::max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
        }
    }

    long long sum = accumulate(x.begin(), x.end(), 0ll);

    std::cout << (sum + dp[0][n - 1]) / 2;
    return 0;
}