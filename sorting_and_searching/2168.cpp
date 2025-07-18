#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    sort(p.begin(), p.end(), [&](int i, int j) {
        if (y[i] == y[j]) {
            return x[i] > x[j];
        }
        return y[i] < y[j];
    });
    std::vector<int> a(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max >= x[p[i]]) {
            a[p[i]] = 1;
        }
        max = std::max(max, x[p[i]]);
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }

    sort(p.begin(), p.end(), [&](int i, int j) {
        if (x[i] == x[j]) {
            return y[i] > y[j];
        }
        return x[i] < x[j];
    });
    std::vector<int> b(n);
    max = 0;
    for (int i = 0; i < n; i++) {
        if (max >= y[p[i]]) {
            b[p[i]] = 1;
        }
        max = std::max(max, y[p[i]]);
    }
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}