#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> k(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i];
    }

    std::multiset<int> s;
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(k[i]);
        if (it == s.end()) {
            s.insert(k[i]);
        } else {
            s.erase(it);
            s.insert(k[i]);
        }
    }

    std::cout << s.size();
    return 0;
}