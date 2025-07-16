#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    sort(p.begin(), p.end());

    int cnt = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        while (l < r && p[l] + p[r] > x) {
            r--;
        }
        if (l == r) {
            break;
        }
        cnt++;
        l++;
        r--;
    }

    int res = n - cnt;
    std::cout << res;
    return 0;
}