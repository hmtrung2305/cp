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

    sort(p.begin(), p.end());

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(p[i] - p[n / 2]);
    }
    std::cout << res;
    return 0;
}