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

    long long res = 0;

    std::map<long long, int> cnt;
    cnt[0] = 1;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        res += cnt[s - x];
        cnt[s]++;
    }

    std::cout << res;
    return 0;
}