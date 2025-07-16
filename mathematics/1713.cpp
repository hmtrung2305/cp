#include <bits/stdc++.h>

void solve() {
    int x;
    std::cin >> x;

    int res = 0;
    for (int i = 1; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            int j = x / i;
            res += (i != j ? 2 : 1);
        }
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