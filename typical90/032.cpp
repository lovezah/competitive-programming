#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
template <typename T, typename U>
bool ckmin(T &a, const U &b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename U>
bool ckmax(T &a, const U &b) {
  return a < b ? a = b, true : false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  int M;
  cin >> M;
  vector<vector<bool>> ban(N, vector<bool>(N));
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ban[x][y] = ban[y][x] = true;
  }
  const int INF = 1 << 29;
  vector<vector<int>> dp(1 << N, vector<int>(N, INF));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    dp[1 << i][i] = A[i][0];
  }
  for (int mask = 0; mask < 1 << N; mask++) {
    int cnt = __builtin_popcount(mask);
    for (int i = 0; i < N; i++) {
      if (mask >> i & 1) {
        for (int j = 0; j < N; j++) {
          if (!(mask >> j & 1) && !ban[i][j]) {
            ckmin(dp[mask | 1 << j][j], dp[mask][i] + A[j][cnt]);
          }
        }
      }
    }
  }
  int ans = *min_element(all(dp.back()));
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
}