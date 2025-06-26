#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION";
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        std::cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2) {
        std::cout << i << " ";
    }
    return 0;
}