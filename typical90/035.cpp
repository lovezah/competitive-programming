#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
struct LowestCommonAncestor {
  int h;
  vector<vector<int>> G, par;
  vector<int> dep;
  bool LCA_BUILD = false;
  LowestCommonAncestor(int n) : G(n), dep(n) {
    h = 1;
    while ((1 << h) <= n) h++;
    par.assign(h, vector<int>(n, -1));
  }
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  void dfs(int u, int p, int d) {
    par[0][u] = p;
    dep[u] = d;
    for (int v : G[u]) {
      if (v != p) {
        dfs(v, u, d + 1);
      }
    }
  }
  void build(int r = 0) {
    LCA_BUILD = true;
    int n = (int)G.size();
    dfs(r, -1, 0);
    for (int i = 0; i + 1 < h; i++) {
      for (int j = 0; j < n; j++) {
        if (par[i][j] != -1) {
          par[i + 1][j] = par[i][par[i][j]];
        }
      }
    }
  }
  int lca(int u, int v) {
    assert(LCA_BUILD);
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 0; i < h; i++) {
      if ((dep[u] - dep[v]) & (1 << i)) u = par[i][u];
    }
    if (u == v) return u;
    for (int i = h - 1; i >= 0; i--) {
      if (par[i][u] != par[i][v]) {
        u = par[i][u];
        v = par[i][v];
      }
    }
    return par[0][u];
  }
  int distance(int u, int v) {
    assert(LCA_BUILD);
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }
};
struct AuxiliaryTree : LowestCommonAncestor {
  using super = LowestCommonAncestor;
  vector<int> tin;
  vector<vector<int>> E;
  bool AT_BUILD = false;
  AuxiliaryTree(int n) : super(n), tin(n), E(n) {}
  void dfs(int u, int p, int& pos) {
    tin[u] = pos++;
    for (int v : G[u]) {
      if (v != p) {
        dfs(v, u, pos);
      }
    }
  }
  void build(int r = 0) {
    super::build(r);
    AT_BUILD = true;
    int pos = 0;
    dfs(r, -1, pos);
  }
  void add_aux_edge(int u, int v) {
    E[u].push_back(v);
    E[v].push_back(u);
  }
  using super::dep;
  using super::lca;
  void query(vector<int> a) {
    assert(AT_BUILD);
    int n = a.size();
    sort(a.begin(), a.end(), [&](int x, int y) { return tin[x] < tin[y]; });
    for (int i = 0; i + 1 < n; i++) {
      a.push_back(lca(a[i], a[i + 1]));
    }
    a.push_back(0);
    sort(a.begin(), a.end(), [&](int x, int y) { return tin[x] < tin[y]; });
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i + 1 < (int)a.size(); i++) {
      add_aux_edge(lca(a[i], a[i + 1]), a[i + 1]);
    }
  }
  void clear(int u = 0, int p = -1) {
    for (int v : E[u]) {
      if (v != p) {
        clear(v, u);
      }
    }
    E[u].clear();
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  AuxiliaryTree AT(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    AT.add_edge(a, b);
  }
  AT.build();
  int Q;
  cin >> Q;
  while (Q--) {
    int K;
    cin >> K;
    vector<int> V(K);
    for (int i = 0; i < K; i++) {
      cin >> V[i];
      V[i]--;
    }
    AT.query(V);
    int ans = 0;
    auto dfs = [&](auto& dfs, int u, int p) -> void {
      for (int v : AT.E[u]) {
        if (v == p) {
          continue;
        }
        ans += AT.dep[v] - AT.dep[u];
        dfs(dfs, v, u);
      }
    };
    dfs(dfs, 0, -1);
    if (V[0] != 0 && sz(AT.E[0]) == 1) {
      ans -= AT.dep[AT.E[0][0]] - AT.dep[0];
    }
    cout << ans << nl;
    AT.clear();
  }
}