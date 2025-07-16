#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::array<int, 3>> c(n);
    for (int i = 0; i < n; i++) {
        int a, b, p;
        std::cin >> a >> b >> p;
        c[i] = {a, b, p};
    }

    sort(c.begin(), c.end(), [&](std::array<int, 3> x, std::array<int, 3> y) {
        return x[1] < y[1];
    });

    long long res = 0;

    std::map<int, long long> dp;
    dp[2e9] = 0;
    for (int i = 0; i < n; i++) {
        long long p = 0;
        auto it = dp.lower_bound(c[i][0]);
        if (it != dp.begin()) {
            it = prev(it);
            p = it->second;
        }

        dp[c[i][1]] = std::max(dp[c[i][1]], p + c[i][2]);

        res = std::max(res, dp[c[i][1]]);
    }
    std::cout << res;
    return 0;
}