#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<vector<int>> dp(1000, vector<int>(3000, -1));
  auto dfs = [&](auto& dfs, int w, int b) -> int {
    if (dp[w][b] != -1) {
      return dp[w][b];
    }
    if (w == 0 && b < 2) {
      return dp[w][b] = 0;
    }
    int ans = 0;
    if (w >= 1) {
      if (!dfs(dfs, w - 1, b + w)) {
        ans = 1;
      }
    }
    if (b >= 2) {
      for (int k = 1; k <= b / 2; k++) {
        if (!dfs(dfs, w, b - k)) {
          ans = 1;
        }
      }
    }
    return dp[w][b] = ans;
  };
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += dfs(dfs, W[i], B[i]);
    cnt %= 2;
    cout << dfs(dfs, W[i], B[i]) << " \n"[i == N - 1];
  }
  if (cnt) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}