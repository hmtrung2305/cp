#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int res = 0;
    while (n) {
        std::string s = std::to_string(n);
        int max = (*max_element(s.begin(), s.end())) - '0';
        n -= max;
        res++;
    }

    std::cout << res;
    return 0;
}