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

    long long res = 0;
    int max = x[0];
    for (int i = 1; i < n; i++) {
        res += std::max(0, max - x[i]);
        max = std::max(max, x[i]);
    }
    std::cout << res;
    return 0;
}