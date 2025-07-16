#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long res = 0;

    std::vector<int> cnt(n);
    cnt[0] = 1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s = (s + a[i] % n + n) % n;
        res += cnt[s];
        cnt[s]++;
    }

    std::cout << res;
    return 0;
}