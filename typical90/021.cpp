#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
vector<vector<int>> StronglyConnectedComponents(const vector<vector<int>>& E) {
  int N = int(E.size());
  vector<bool> done(N);
  vector<int> pos(N, -1), stack;
  vector<vector<int>> res;
  auto dfs = [&](auto& dfs, int u) -> int {
    int low = pos[u] = int(stack.size());
    stack.push_back(u);
    for (int v : E[u]) {
      if (!done[v]) {
        low = min(low, pos[v] == -1 ? dfs(dfs, v) : pos[v]);
      }
    }
    if (low == pos[u]) {
      res.emplace_back(stack.begin() + low, stack.end());
      for (int v : res.back()) {
        done[v] = true;
      }
      stack.resize(low);
    }
    return low;
  };
  for (int i = 0; i < N; i++) {
    if (!done[i]) {
      dfs(dfs, i);
    }
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
  }
  auto scc = StronglyConnectedComponents(E);
  ll ans = 0;
  for (int i = 0; i < sz(scc); i++) {
    int cnt = sz(scc[i]);
    ans += (ll)cnt * (cnt - 1) / 2;
  }
  cout << ans << endl;
}