#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int res = 1;
    for (int i = 0; i < n; i++) {
        res <<= 1;
        res %= MOD;
    }

    std::cout << res;
    return 0;
}