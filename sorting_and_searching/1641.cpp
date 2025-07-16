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
        for (int j = i + 1; j < n; j++) {
            if (x > a[i] + a[j] && 
                p.count(x - a[i] - a[j]) && 
                p[x - a[i] - a[j]] != i &&
                p[x - a[i] - a[j]] != j) {
                std::cout << i + 1 << " " << j + 1 << " " << p[1ll * x - a[i] - a[j]] + 1;
                return 0;
            }
        }
    }

    std::cout << "IMPOSSIBLE";
    return 0;
}