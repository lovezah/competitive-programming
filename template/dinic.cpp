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