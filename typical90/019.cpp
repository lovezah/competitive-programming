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
  vector<int> A(N + N);
  for (int i = 0; i < N + N; i++) {
    cin >> A[i];
  }
  const int INF = 1 << 29;
  vector<vector<int>> dp(N + N, vector<int>(N + N, INF));
  for (int i = 0; i < N + N; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i + 1 < N + N; i++) {
    dp[i][i + 1] = abs(A[i] - A[i + 1]);
  }
  for (int len = 4; len <= N + N; len += 2) {
    for (int l = 0; l + len - 1 < N + N; l++) {
      int r = l + len - 1;
      dp[l][r] = dp[l + 1][r - 1] + abs(A[l] - A[r]);
      for (int k = l + 1; k + 1 <= r; k += 2) {
        ckmin(dp[l][r], dp[l][k] + dp[k + 1][r]);
      }
    }
  }
  cout << dp[0][N + N - 1] << endl;
}