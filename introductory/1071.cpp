#include <bits/stdc++.h>

void solve() {
    int y, x;
    std::cin >> y >> x;

    long long res = 0;
    if (y >= x) {
        res = 1ll * (y - 1) * (y - 1);
        if (y % 2 == 0) {
            res += y + y - x;
        } else {
            res += x;
        }
    } else {
        res = 1ll * (x - 1) * (x - 1);
        if (x % 2 == 1) {
            res += x + x - y;
        } else {
            res += y;
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