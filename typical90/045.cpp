// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define all(v) (v).begin(), (v).end()
// #define sz(v) ((int)(v).size())
// const char nl = '\n';
// ll square(ll x) { return x * x; }
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int N, K;
//   cin >> N >> K;
//   vector<int> X(N), Y(N);
//   for (int i = 0; i < N; i++) {
//     cin >> X[i] >> Y[i];
//   }
//   vector<vector<int>> ids;
//   ll ans = 1ll << 60;
//   auto dfs = [&](auto dfs, int u, ll max_cur) -> void {
//     if (u == N) {
//       if (sz(ids) == K) {
//         ans = min(ans, max_cur);
//       }
//     } else {
//       ids.emplace_back(vector<int>{u});
//       if (sz(ids) <= K) {
//         dfs(dfs, u + 1, max_cur);
//       }
//       ids.pop_back();
//       for (int i = 0; i < sz(ids); i++) {
//         ids[i].emplace_back(u);
//         ll cur = 0;
//         for (int j = 0; j < sz(ids[i]) - 1; j++) {
//           int v = ids[i][j];
//           cur = max(cur, square(X[u] - X[v]) + square(Y[u] - Y[v]));
//         }
//         if (max(max_cur, cur) < ans) {
//           dfs(dfs, u + 1, max(max_cur, cur));
//         }
//         ids[i].pop_back();
//       }
//     }
//   };
//   dfs(dfs, 0, 0);
//   cout << ans << endl;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
ll square(ll x) { return x * x; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  auto dist = [&](int i, int j) -> ll {
    ll x = X[i] - X[j];
    ll y = Y[i] - Y[j];
    return x * x + y * y;
  };
  vector<ll> d(1 << N);
  for (int i = 0; i < 1 << N; i++) {
    vector<int> p;
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        p.push_back(j);
      }
    }
    for (int j = 0; j < sz(p); j++) {
      for (int k = j + 1; k < sz(p); k++) {
        d[i] = max(d[i], dist(p[j], p[k]));
      }
    }
  }
  const ll INF = 1ll << 60;
  vector<vector<ll>> dp(1 << N, vector<ll>(K + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < 1 << N; i++) {
    for (int k = 1; k <= K; k++) {
      if (__builtin_popcount(i) < k) {
        continue;
      }
      for (int j = i; j > 0; j = (j - 1) & i) {
        dp[i][k] = min(dp[i][k], max(dp[i - j][k - 1], d[j]));
      }
    }
  }
  cout << dp.back().back() << endl;
}