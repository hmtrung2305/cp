#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, n;
    std::cin >> x >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::set<int> sp;
    sp.insert(0);
    sp.insert(x);
    std::multiset<int> s;
    s.insert(x);
    for (int i = 0; i < n; i++) {
        auto r = sp.upper_bound(p[i]);
        auto l = prev(r);

        s.erase(s.find(*r - *l));
        s.insert(*r - p[i]);
        s.insert(p[i] - *l);
        sp.insert(p[i]);

        std::cout << *s.rbegin() << " ";
    }

    return 0;
}