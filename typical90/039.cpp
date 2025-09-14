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
  vector<vector<int>> E(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  ll ans = 0;
  auto dfs = [&](auto dfs, int u, int p) -> int {
    int sz = 1;
    for (int v : E[u]) {
      if (v == p) {
        continue;
      }
      sz += dfs(dfs, v, u);
    }
    ans += (ll)sz * (N - sz);
    return sz;
  };
  dfs(dfs, 0, -1);
  cout << ans << endl;
}