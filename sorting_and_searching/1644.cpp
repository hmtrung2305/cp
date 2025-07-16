#include <bits/stdc++.h>

const long long INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<long long> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    long long res = -INF;
    std::multiset<long long> s;
    for (int i = a; i <= n; i++) {
        if (i > b) {
            s.erase(s.find(sum[i - b - 1]));
        }
        s.insert(sum[i - a]);
        res = std::max(res, sum[i] - *s.begin());
    }
    std::cout << res;
    return 0;
}