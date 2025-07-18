#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, t;
    std::cin >> n >> t;

    std::vector<int> k(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i];
    }

    auto check = [&](long long x) {
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += x / k[i];
        }
        return cnt >= t;
    };

    long long min = *min_element(k.begin(), k.end());
    long long lo = 1, hi = min * t;
    while (lo < hi) {
        long long x = (lo + hi) / 2;
        if (check(x)) {
            hi = x;
        } else {
            lo = x + 1;
        }
    }

    std::cout << lo;
    return 0;
}