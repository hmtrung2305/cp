#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            res++;
            i++;
            j++;
        } else if (a[i] + k < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    std::cout << res;
    return 0;
}