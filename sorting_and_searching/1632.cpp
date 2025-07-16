#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::array<int, 2>> c(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        c[i] = {a, b};
    }

    sort(c.begin(), c.end());

    int res = 0;
    std::multiset<int> s;
    for (auto [a, b] : c) {
        while (!s.empty() && *s.begin() <= a) {
            s.erase(s.begin());
        }
        if (s.size() < k) {
            res++;
            s.insert(b);
        } else if (*s.rbegin() > b) {
            auto it = prev(s.end());
            s.erase(it);
            s.insert(b);
        }
    }

    std::cout << res;
    return 0;
}