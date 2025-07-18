#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::array<int, 2>> c(n);
    for (int i = 0; i < n; i++) {
        int a, d;
        std::cin >> a >> d;
        c[i] = {a, d};
    }

    sort(c.begin(), c.end());

    long long res = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += c[i][0];
        res += c[i][1] - cur;
    }

    std::cout << res;
    return 0;
}