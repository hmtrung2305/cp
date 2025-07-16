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

    std::vector<int> dp;
    for (int i = 0; i < n; i++) {
        if (dp.empty() || x[i] > dp.back()) {
            dp.push_back(x[i]);
        } else {
            int p = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();
            dp[p] = x[i];
        }
    }

    std::cout << dp.size();
    return 0;
}