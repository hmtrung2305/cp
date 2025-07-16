#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        p[x] = i;
    }

    int res = 1;
    for (int i = 1; i < n; i++) {
        if (p[i] < p[i - 1]) {
            res++;
        }
    }
    std::cout << res;
    return 0;
}