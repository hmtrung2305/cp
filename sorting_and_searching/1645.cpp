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

    std::stack<std::array<int, 2>> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && x[i] <= x[stk.top()[1]]) {
            stk.pop();
        }
        std::cout << (stk.empty() ? 0 : stk.top()[1] + 1) << " ";
        stk.push({x[i], i});
    }

    return 0;
}