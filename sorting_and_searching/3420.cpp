#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::map<int, int> cnt;

    long long res = 0;
    for (int r = 0, l = 0; r < n; r++) {
        cnt[x[r]]++;
        while (cnt[x[r]] > 1) {
            cnt[x[l]]--;
            l++;
        }
        res += r - l + 1;
    }

    std::cout << res;
    return 0;
}