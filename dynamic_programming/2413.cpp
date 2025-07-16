#include <bits/stdc++.h>

const int N = 1e6;
const int MOD = 1e9 + 7;

int dp[N + 1][2];

void solve() {
    int n;
    std::cin >> n;

    int res = (dp[n][0] + dp[n][1]) % MOD;
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (4ll * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2ll * dp[i - 1][1]) % MOD;
    }

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}