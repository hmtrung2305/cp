#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int res = 0;
    for (int i = 5; i <= n; i *= 5) {
        res += n / i;
    }

    std::cout << res;
    return 0;
}