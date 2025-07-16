#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    std::cout << dp[n][m] << "\n";

    std::vector<int> res;
    while (dp[n][m] != 0) {
        if (a[n - 1] == b[m - 1]) {
            res.push_back(a[n - 1]);
            n--;
            m--;
        } else if (dp[n - 1][m] == dp[n][m]) {
            n--;
        } else {
            m--;
        }
    }

    reverse(res.begin(), res.end());
    for (int x : res) {
        std::cout << x << " ";
    }
    return 0;
}