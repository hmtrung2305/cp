#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
        x = q.front();
        q.pop();
        std::cout << x << " ";
    }

    return 0;
}