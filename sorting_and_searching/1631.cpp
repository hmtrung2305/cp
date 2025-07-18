#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    long long sum = accumulate(t.begin(), t.end(), 0ll);
    int max = *max_element(t.begin(), t.end());

    long long res = std::max(2ll * max, sum);
    std::cout << res;
    return 0;
}