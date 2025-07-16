#include <bits/stdc++.h>

int mex(const std::vector<int> &x) {
    std::vector<int> a(x);
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != i) {
            return i;
        }
    }
    return a.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> res(n, std::vector<int>(n));
    std::vector<std::vector<int>> col(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::vector<int> x = col[j];
            for (int k = 0; k < j; k++) {
                x.push_back(res[i][k]);
            }

            res[i][j] = mex(x);

            col[j].push_back(res[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << res[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}