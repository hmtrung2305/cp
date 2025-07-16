#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    if (s.size() == 1) {
        std::cout << s;
        return 0;
    }

    std::vector<int> cnt(26);
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'A']++;
    }

    std::vector<int> p;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > s.size() / 2) {
            std::cout << -1;
            return 0;
        }
        if (cnt[i]) {
            p.push_back(i);
        }
    }

    for (auto x : p) {
        std::cout << char(x + 'A') << " " << cnt[x] << "\n";
    }

    for (int i = 0, j = 1; j < p.size(); ) {
        std::cout << char(p[i] + 'A') << char(p[j] + 'A');
        // std::cout << cnt[p[i]] << " " << cnt[p[j]] << "\n";
        cnt[p[i]]--;
        cnt[p[j]]--;
        if (cnt[j] == 0) {
            j++;
        }
        if (cnt[i] == 0) {
            i = j;
            j++;
        }
    }

    return 0;
}