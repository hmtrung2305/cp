#include <bits/stdc++.h>

void work(int n, int a, int b, int c) {
    if (n == 1) {
        std::cout << a << " " << c << "\n";
        return;
    }

    work(n - 1, a, c, b);
    work(1, a, b, c);
    work(n - 1, b, a, c);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::cout << (1 << n) - 1 << "\n";
    work(n, 1, 2, 3);
    return 0;
}