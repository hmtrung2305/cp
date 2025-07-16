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

    sort(x.begin(), x.end());

    long long s = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > s + 1) {
            break;
        }
        s += x[i];
    }
    std::cout << s + 1;
    return 0;
}