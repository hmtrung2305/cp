#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<int, std::array<int, 2>> p;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            p[a[i] + a[j]] = {i, j};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = x - a[i] - a[j];
            if (p.count(s) && 
                p[s][0] != i && p[s][0] != j && 
                p[s][1] != i && p[s][1] != j) {
                std::cout << i + 1 << " " << j + 1 << " " << p[s][0] + 1 << " " << p[s][1] + 1;
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE";
    return 0;
}