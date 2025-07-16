#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::string> s{"0", "1"};
    for (int i = 2; i <= n; i++) {
        std::vector<std::string> t;
        int m = s.size();
        for (int j = 0; j < m; j++) {
            t.push_back('0' + s[j]);
        }
        for (int j = m - 1; j >= 0; j--) {
            t.push_back('1' + s[j]);
        }
        s.swap(t);
    }

    for (int i = 0; i < s.size(); i++) {
        std::cout << s[i] << "\n";
    }
    return 0;
}