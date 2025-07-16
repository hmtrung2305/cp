#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    long long res = 0;

    int cnt = 0;
    std::map<int, int> m;
    for (int l = 0, r = 0; r < n; r++) {
        cnt += (m[x[r]] == 0);
        m[x[r]]++;
        while (cnt > k) {
            m[x[l]]--;
            cnt -= (m[x[l]] == 0);
            l++;
        }
        res += r - l + 1;
    }

    std::cout << res;
    return 0;
}