#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
const int nax = 1007;
int dp[nax][nax][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  int sx, sy;
  cin >> sx >> sy;
  sx--;
  sy--;
  int ex, ey;
  cin >> ex >> ey;
  ex--;
  ey--;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  const int dxy[] = {0, 1, 0, -1, 0};
  const int DIR[] = {0, 1, 2, 3};
  const int inf = 1e9;
  int ans = inf;
  for (int d : DIR) {
    memset(dp, -1, sizeof dp);
    dp[sx][sy][d] = 0;
    deque<tuple<int, int, int>> Q;
    Q.emplace_back(sx, sy, d);
    while (!Q.empty()) {
      auto [x, y, dir] = Q.front();
      Q.pop_front();
      for (int nd : DIR) {
        int nx = x + dxy[nd];
        int ny = y + dxy[nd + 1];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
          continue;
        }
        if (S[nx][ny] == '#') {
          continue;
        }
        if (dp[nx][ny][nd] != -1) {
          continue;
        }
        dp[nx][ny][nd] = dp[x][y][dir] + (nd != dir);
        if (nd == dir) {
          Q.emplace_front(nx, ny, nd);
        } else {
          Q.emplace_back(nx, ny, nd);
        }
      }
    }
    for (int ed : DIR) {
      if (dp[ex][ey][ed] != -1) {
        ans = min(ans, dp[ex][ey][ed]);
      }
    }
  }
  cout << ans << endl;
}