#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> k(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i];
    }

    int res = 0;
    std::map<int, int> cnt;
    for (int l = 0, r = 0; r < n; r++) {
        cnt[k[r]]++;
        while (cnt[k[r]] == 2) {
            cnt[k[l]]--;
            l++;
        }
        res = std::max(res, r - l + 1);
    }
    std::cout << res;
    return 0;
}