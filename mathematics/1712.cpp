#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int power(int a, int n, int m) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = (1ll * res * a) % m;
        }
        a = (1ll * a * a) % m;
        n >>= 1;
    }
    return res;
}

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << power(a, power(b, c, MOD - 1), MOD) << "\n";
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