#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
template <class T>
struct dinic {
  int n;
  vector<tuple<int, int, T>> e;
  vector<vector<int>> adj;
  vector<int> lev;
  dinic(int n_) : n(n_), adj(n) {}
  int add_edge(int u, int v, T c) {
    int i = e.size();
    e.emplace_back(u, v, c);
    e.emplace_back(v, u, 0);
    adj[u].push_back(i);
    adj[v].push_back(i ^ 1);
    return i;
  }
  T max_flow(int s, int t) {
    T flow = 0;
    queue<int> q;
    vector<int> cur;
    auto bfs = [&]() {
      lev.assign(n, -1);
      lev[s] = 0;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : adj[u]) {
          auto [_, v, c] = e[i];
          if (c > 0 && lev[v] == -1) {
            lev[v] = lev[u] + 1;
            q.push(v);
          }
        }
      }
      return ~lev[t];
    };
    auto dfs = [&](auto &&dfs, int u, T lim) -> T {
      if (u == t) {
        return lim;
      }
      T res = 0;
      for (int &i = cur[u]; i < (int)adj[u].size() && lim > 0; i++) {
        int j = adj[u][i];
        auto [_, v, c] = e[j];
        if (lev[v] == lev[u] + 1 && c > 0) {
          T d = dfs(dfs, v, min(c, lim));
          if (d > 0) {
            lim -= d;
            res += d;
            get<2>(e[j]) -= d;
            get<2>(e[j ^ 1]) += d;
          }
        }
      }
      return res;
    };
    while (bfs()) {
      cur.assign(n, 0);
      while (T f = dfs(dfs, s, numeric_limits<T>::max())) {
        flow += f;
      }
    }
    return flow;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, W;
  cin >> N >> W;
  ll sum = 0;
  vector<int> A(N);
  for (int i : views::iota(0, N)) {
    cin >> A[i];
    sum += A[i];
  }
  int source = N, sink = N + 1;
  dinic<ll> D(N + 2);
  for (int i : views::iota(0, N)) {
    D.add_edge(source, i, A[i]);
    D.add_edge(i, sink, W);
  }
  const ll INF = 1ll << 59;
  for (int i : views::iota(0, N)) {
    int k;
    cin >> k;
    for (int j : views::iota(0, k)) {
      int c;
      cin >> c;
      c--;
      D.add_edge(c, i, INF);
    }
  }
  cout << max(0ll, sum - D.max_flow(source, sink)) << endl;
}