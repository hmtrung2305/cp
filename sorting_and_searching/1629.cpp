#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::array<int, 2>> c(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        c[i] = {a, b};
    }

    sort(c.begin(), c.end(), [&](std::array<int, 2> x, std::array<int, 2> y) {
        return x[1] < y[1];
    });

    int res = 1;
    int max = c[0][1];
    for (int i = 0; i < n; i++) {
        if (c[i][0] >= max) {
            res++;
            max = c[i][1];
        }
    }
    std::cout << res;
    return 0;
}