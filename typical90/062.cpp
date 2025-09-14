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
  vector<int> A(N), B(N);
  vector<vector<int>> E(N);
  vector<int> que;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    if (A[i] != i) {
      E[A[i]].push_back(i);
    } else {
      que.push_back(i);
    }
    if (B[i] != i) {
      E[B[i]].push_back(i);
    } else {
      que.push_back(i);
    }
  }
  sort(all(que));
  que.erase(unique(all(que)), que.end());
  if (que.empty()) {
    cout << -1 << endl;
    return 0;
  }
  vector<bool> used(N);
  vector<int> ans;
  for (int i = 0; i < sz(que); i++) {
    if (used[que[i]]) continue;
    auto dfs = [&](auto dfs, int u, int p) -> void {
      ans.emplace_back(u);
      for (int v : E[u]) {
        if (v == p || used[v]) continue;
        used[v] = true;
        dfs(dfs, v, u);
      }
    };
    used[que[i]] = true;
    dfs(dfs, que[i], -1);
  }
  if (sz(ans) != N) {
    cout << -1 << endl;
    return 0;
  }
  reverse(all(ans));
  for (int i = 0; i < N; i++) {
    cout << ans[i] + 1 << nl;
  }
}