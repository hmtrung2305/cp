#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    int max = *max_element(h.begin(), h.end());
    long long sum = accumulate(h.begin(), h.end(), 0ll);

    auto check = [&](long long x) {
        long long s = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            s += h[i];
            if (s > x) {
                cnt++;
                s = h[i];
            }
        }
        return cnt <= k; 
    };

    long long lo = max, hi = sum;
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