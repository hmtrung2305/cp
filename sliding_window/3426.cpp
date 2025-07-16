#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> x(n);
    int a, b, c;
    std::cin >> x[0] >> a >> b >> c;

    long long s = x[0];
    for (int i = 1; i < n; i++) {
        x[i] = (1ll * a * x[i - 1] + b) % c;
        if (i < k) {
            s ^= x[i];
        }
    }

    long long res = s;
    for (int i = k; i < n; i++) {
        s ^= x[i - k];
        s ^= x[i];
        res ^= s;
    }

    std::cout << res;
    return 0;
}