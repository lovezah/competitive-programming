#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(M), B(M);
  vector<vector<int>> E(N);
  vector<int> deg(N);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    E[A[i]].push_back(B[i]);
    deg[B[i]] += 1;
  }
  vector<int> que;
  for (int i = 0; i < N; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  vector<vector<int>> ans;
  vector<int> cur(N, -1);
  auto dfs = [&](auto& dfs, int d) -> bool {
    if (d == N) {
      ans.push_back(cur);
      return true;
    }
    if (sz(que) == 0) {
      return false;
    }
    for (int i = sz(que) - 1; i >= 0; i--) {
      if (sz(ans) == K) {
        break;
      }
      int u = que[i];
      cur[d] = u;
      que.erase(que.begin() + i);
      for (int v : E[u]) {
        deg[v] -= 1;
        if (deg[v] == 0) {
          que.push_back(v);
        }
      }
      if (!dfs(dfs, d + 1)) {
        return false;
      }
      for (int v : E[u]) {
        deg[v] += 1;
        if (deg[v] == 1) {
          que.pop_back();
        }
      }
      que.insert(que.begin() + i, u);
    }
    return true;
  };
  dfs(dfs, 0);
  if (sz(ans) != K) {
    cout << -1 << endl;
  } else {
    for (auto a : ans) {
      for (int j = 0; j < N; j++) {
        cout << a[j] + 1 << " \n"[j == N - 1];
      }
    }
  }
}