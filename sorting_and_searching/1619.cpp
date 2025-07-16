#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::map<int, int> t;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        t[a]++;
        t[b + 1]--;
    }

    int res = 0;
    int c = 0;
    for (auto [_, x] : t) {
        c += x;
        res = std::max(res, c);
    }

    std::cout << res;
    return 0;
}