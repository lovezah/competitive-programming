struct AuxiliaryTree : LowestCommonAncestor {
  using super = LowestCommonAncestor;
  vector<int> tin;
  vector<vector<int>> E;
  bool AT_BUILD = false;
  AuxiliaryTree(int n) : super(n), tin(n), E(n) {}
  void dfs(int u, int p, int &pos) {
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
