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
  vector<int> dep(N, -1);
  dep[0] = 0;
  vector<int> que(1, 0);
  for (int i = 0; i < sz(que); i++) {
    int u = que[i];
    for (int v : E[u]) {
      if (dep[v] < 0) {
        dep[v] = dep[u] + 1;
        que.push_back(v);
      }
    }
  }
  for (int d = 0; d < 2; d++) {
    vector<int> res;
    for (int i = 0; i < N; i++) {
      if (dep[i] % 2 == d) {
        res.push_back(i);
      }
    }
    if (sz(res) >= N / 2) {
      res.resize(N / 2);
      for (int j = 0; j < sz(res); j++) {
        cout << res[j] + 1 << " \n"[j == sz(res) - 1];
      }
      return 0;
    }
  }
}