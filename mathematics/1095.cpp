#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void solve() {
    int a, b;
    std::cin >> a >> b;

    int res = 1;
    while (b) {
        if (b & 1) {
            res = (1ll * res * a) % MOD;
        }
        a = (1ll * a * a) % MOD;
        b >>= 1;
    }
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}