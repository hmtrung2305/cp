#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::multiset<int> s;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        s.insert(h);
    }

    for (int i = 0; i < m; i++) {
        int t;
        std::cin >> t;
        auto it = s.upper_bound(t);
        if (it == s.begin()) {
            std::cout << -1 << "\n";
        } else {
            it = prev(it);
            std::cout << *it << "\n";
            s.erase(it);
        }
    }

    return 0;
}