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
const int MAX = 5000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(3));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> A[i][j];
    }
  }
  sort(all(A), [&](auto x, auto y) { return make_tuple(x[0], x[1], -x[2]) < make_tuple(y[0], y[1], -y[2]); });
  vector<ll> dp(MAX + 1);
  for (int i = 0; i < N; i++) {
    int D = A[i][0];
    int C = A[i][1];
    int S = A[i][2];
    auto ndp = dp;
    for (int j = 1; j + C - 1 <= D; j++) {
      ckmax(ndp[j + C - 1], dp[j - 1] + S);
    }
    dp = ndp;
  }
  cout << *max_element(all(dp)) << endl;
}