#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (a <= 2 * b && b <= 2 * a && (a + b) % 3 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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