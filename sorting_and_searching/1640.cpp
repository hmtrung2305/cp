#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<int, int> p;
    for (int i = 0; i < n; i++) {
        p[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (p.count(x - a[i]) && p[x - a[i]] != i) {
            std::cout << i + 1 << " " << p[x - a[i]] + 1;
            return 0;
        }
    }

    std::cout << "IMPOSSIBLE";
    return 0;
}