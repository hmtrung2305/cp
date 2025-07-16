#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        dsu.merge(u, v);
    }

    std::vector<int> res;
    for (int u = 0; u < n; u++) {
        if (dsu.find(u) == u) {
            res.push_back(u);
        }
    }

    std::cout << res.size() - 1 << "\n";
    for (int i = 1; i < res.size(); i++) {
        std::cout << res[i - 1] + 1 << " " << res[i] + 1 << "\n";
    }
    return 0;
}