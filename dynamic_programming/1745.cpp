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

    int sum = accumulate(x.begin(), x.end(), 0);

    std::vector<bool> dp(sum + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j > 0; j--) {
            if (j - x[i] >= 0 && dp[j - x[i]]) {
                dp[j] = true;
            }
        }
    }

    std::vector<int> res;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            res.push_back(i);
        }
    }

    std::cout << res.size() << "\n";
    for (int a : res) {
        std::cout << a << " ";
    }
    return 0;
}