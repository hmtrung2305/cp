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

    int res = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s ^= a[i];
        res = std::max(res, s);
    }

    std::cout << res;
    return 0;
}