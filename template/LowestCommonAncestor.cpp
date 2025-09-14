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
