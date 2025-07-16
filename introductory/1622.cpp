#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    sort(s.begin(), s.end());

    std::vector<std::string> res;
    do {
        res.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    std::cout << res.size() << "\n";
    for (std::string x : res) {
        std::cout << x << "\n";
    }
    return 0;
}