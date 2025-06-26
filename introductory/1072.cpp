#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int x = i * i;
        long long res = 1ll * x * (x - 1) / 2;
        if (i > 2) {
            res -= 4 * (i - 1) * (i - 2);
        }
        std::cout << res << "\n";
    }

    return 0;
}