vector<vector<int>> StronglyConnectedComponents(const vector<vector<int>>& E) {
  int N = int(E.size());
  vector<bool> done(N);
  vector<int> pos(N, -1), stack;
  vector<vector<int>> res;
  auto dfs = [&](auto& dfs, int u) -> int {
    int low = pos[u] = int(stack.size());
    stack.push_back(u);
    for (int v : E[u]) {
      if (!done[v]) {
        low = min(low, pos[v] == -1 ? dfs(dfs, v) : pos[v]);
      }
    }
    if (low == pos[u]) {
      res.emplace_back(stack.begin() + low, stack.end());
      for (int v : res.back()) {
        done[v] = true;
      }
      stack.resize(low);
    }
    return low;
  };
  for (int i = 0; i < N; i++) {
    if (!done[i]) {
      dfs(dfs, i);
    }
  }
  reverse(res.begin(), res.end());
  return res;
}