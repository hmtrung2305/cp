#include <bits/stdc++.h>

long long mul(long long a, long long b, long long m) {
    return static_cast<__int128>(a) * b % m;
}
long long power(long long a, long long b, long long m) {
    long long res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
bool isprime(long long n) {
    if (n < 2)
        return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    long long d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n)
            return true;
        long long x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}

void solve() {
    long long n;
    std::cin >> n;

    do {
        n++;
    } while (!isprime(n));

    std::cout << n << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}