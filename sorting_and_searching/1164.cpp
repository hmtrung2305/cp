#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) {
        return a[x] < a[y];
    });

    int cnt = 0;
    std::vector<int> res(n);
    std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<std::array<int, 2>>> h;
    for (int i = 0; i < n; i++) {
        if (h.empty() || h.top()[0] >= a[p[i]]) {
            cnt++;
            h.push({b[p[i]], cnt});
            res[p[i]] = cnt;
        } else {
            auto [x, y] = h.top();
            h.pop();
            h.push({b[p[i]], y});
            res[p[i]] = y;
        }
    }

    std::cout << cnt << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " \n"[i == n - 1];
    }
    return 0;
}