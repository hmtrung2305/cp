#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<bool> vis(n);
    for (int i = 1; i < n; i++) {
        int a;
        std::cin >> a;
        a--;
        vis[a] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            std::cout << i + 1;
            return 0;
        }
    }

    return 0;
}