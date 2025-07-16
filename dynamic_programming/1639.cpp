#include <bits/stdc++.h>

const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s, t;
    std::cin >> s >> t;

    int n = s.size();
    int m = t.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j] + 1;
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    std::cout << dp[n][m];
    return 0;
}