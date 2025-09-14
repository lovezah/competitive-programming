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
  auto bfs = [&](int root) -> vector<int> {
    vector<int> d(N, -1);
    d[root] = 0;
    vector<int> que(1, root);
    for (int i = 0; i < sz(que); i++) {
      int u = que[i];
      for (int v : E[u]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          que.push_back(v);
        }
      }
    }
    return d;
  };
  auto bfs0 = bfs(0);
  int u = max_element(all(bfs0)) - bfs0.begin();
  auto bfsu = bfs(u);
  int v = max_element(all(bfsu)) - bfsu.begin();
  cout << bfsu[v] + 1 << nl;
}