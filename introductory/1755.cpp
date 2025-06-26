#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }

    int c = 0, p = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            c++;
            p = i;
        }
    }

    if (c > 1 || c % 2 != n % 2) {
        std::cout << "NO SOLUTION";
        return 0;
    }

    std::string t(n, '#');

    if (c == 1) {
        t[n / 2] = p + 'A';
        cnt[p]--;
    }

    for (int i = 0, x = 0; i < n / 2; i++) {
        while (!cnt[x]) {
            x++;
        }
        t[i] = x + 'A';
        t[t.size() - 1 - i] = x + 'A';
        cnt[x] -= 2;
    }

    std::cout << t;
    return 0;
}