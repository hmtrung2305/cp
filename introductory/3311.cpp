#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                std::cout << (s[i][j] == 'A' ? 'C' : 'A');
            } else {
                std::cout << (s[i][j] == 'B' ? 'D' : 'B');
            }
        }
        std::cout << "\n";
    }

    return 0;
}