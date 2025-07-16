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

    long long res = x[0];
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += x[i];
        res = std::max(res, s);
        if (s < 0) {
            s = 0;
        }
    }

    std::cout << res;
    return 0;
}