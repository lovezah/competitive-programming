struct matching {
  int N, M;
  vector<vector<int>> E;
  vector<int> A;
  vector<int> B;
  vector<int> was;
  int res;
  int iter;
  matching(int _N, int _M) : N(_N), M(_M) {
    assert(0 <= N && 0 <= M);
    A = vector<int>(N, -1);
    B = vector<int>(M, -1);
    was = vector<int>(N, 0);
    E.resize(N);
    res = iter = 0;
  }
  void add_edge(int u, int v) {
    assert(0 <= u && u < N && 0 <= v && v < M);
    E[u].push_back(v);
  }
  bool dfs(int u) {
    was[u] = iter;
    for (int v : E[u]) {
      if (B[v] == -1) {
        A[u] = v;
        B[v] = u;
        return true;
      }
    }
    for (int v : E[u]) {
      if (was[B[v]] != iter && dfs(B[v])) {
        A[u] = v;
        B[v] = u;
        return true;
      }
    }
    return false;
  }
  int solve() {
    mt19937_64 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
    for (int i = 0; i < N; i++) {
      shuffle(E[i].begin(), E[i].end(), rng);
    }
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < N; i++) {
        if (A[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }
};