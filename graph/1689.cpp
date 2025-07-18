#include <bits/stdc++.h>
 
const int N = 8;
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
 
int dis[N][N];
 
int cntMove(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || dis[x][y] > 0) {
            continue;
        }
        cnt++;
    }
    return cnt;
}
 
bool dfs(int x, int y, int cnt) {
    if (cnt == N * N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << dis[i][j] << " \n"[j == N - 1];
            }
        }
        return true;
    }
 
    std::vector<std::pair<int, int>> c;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || dis[nx][ny] > 0) {
            continue;
        }
        c.push_back({cntMove(nx, ny), i});
    }
    sort(c.begin(), c.end());
 
    for (auto [_, i] : c) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || dis[nx][ny] > 0) {
            continue;
        }
        dis[nx][ny] = cnt + 1;
        if (dfs(nx, ny, cnt + 1)) {
            return true;
        }
        dis[nx][ny] = 0;
    }
    return false;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
 
    int x, y;
    std::cin >> x >> y;
    x--; y--;
 
    dis[y][x] = 1;
    dfs(y, x, 1);
    return 0;
}