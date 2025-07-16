#include <bits/stdc++.h>

const int X = 1e6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> cnt(X + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    int res = 1;
    for (int i = 2; i <= X; i++) {
        int c = 0;
        for (int j = i; j <= X; j += i) {
            c += cnt[j];
        }
        if (c > 1) {
            res = i;
        }
    }

    std::cout << res;
    return 0;
}