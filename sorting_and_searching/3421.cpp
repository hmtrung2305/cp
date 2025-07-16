#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[x[i]]++;
    }

    int res = 1;
    for (auto [_, c] : cnt) {
        res = (1ll * res * (c + 1)) % MOD;
    }
    res = (res - 1 + MOD) % MOD;

    std::cout << res;
    return 0;
}