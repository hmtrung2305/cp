#include <bits/stdc++.h>

const int N = 8;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::vector<std::string> s(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
    }

    int res = 0;

    std::vector<bool> col(N);
    std::vector<bool> md(2 * N - 1), sd(2 * N - 1);
    std::function<void(int)> work = [&](int x) {
        if (x == N) {
            res++;
            return;
        }
        for (int y = 0; y < N; y++) {
            if (col[y] || s[x][y] == '*' || md[x + y] || sd[x - y + N - 1]) {
                continue;
            }
            col[y] = true;
            md[x + y] = true;
            sd[x - y + N - 1] = true;
            work(x + 1);
            col[y] = false;
            md[x + y] = false;
            sd[x - y + N - 1] = false;
        }
    };
    work(0);

    std::cout << res;
    return 0;
}