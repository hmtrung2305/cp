#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        int j = 1;
        while (i + 1 < s.size() && s[i] == s[i + 1]) {
            i++;
            j++;
        }
        res = std::max(res, j);
    }

    std::cout << res;
    return 0;
}