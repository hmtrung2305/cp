#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    long long sum = accumulate(p.begin(), p.end(), 0ll);

    long long res = sum;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long s = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                s += p[i];
            }
        }
        res = std::min(res, llabs(s - llabs(sum - s)));
    }

    std::cout << res;
    return 0;
}