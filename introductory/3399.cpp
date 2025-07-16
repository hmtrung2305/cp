#include <bits/stdc++.h>

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    int d = n - a - b;

    if (d < 0 || (d != n && (a == 0 || b == 0))) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";

    std::vector<std::array<int, 2>> res(n);
    for (int i = 0; i < d; i++) {
        res[i][0] = i + 1;
        res[i][1] = i + 1;
    }

    std::vector<int> x(a + b);
    iota(x.begin(), x.end(), d + 1);
    rotate(x.begin(), x.begin() + a, x.end());

    for (int i = d; i < n; i++) {
        res[i][0] = i + 1;
        res[i][1] = x[i - d];
    }

    for (int i = 0; i < n; i++) {
        std::cout << res[i][0] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        std::cout << res[i][1] << " \n"[i == n - 1];
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