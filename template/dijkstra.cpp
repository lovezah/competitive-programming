template <typename T>
vector<T> dijkstra(const vector<vector<pair<int, int>>> &E, int source = 0) {
  const T INF = numeric_limits<T>::max() / 2;
  int N = int(E.size());
  vector<T> d(N, INF);
  d[source] = 0;
  using dij_t = pair<T, int>;
  priority_queue<dij_t, vector<dij_t>, greater<dij_t>> PQ;
  PQ.emplace(d[source], source);
  while (!PQ.empty()) {
    auto [exp, u] = PQ.top();
    PQ.pop();
    if (exp != d[u]) {
      continue;
    }
    for (auto [v, w] : E[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        PQ.emplace(d[v], v);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (d[i] == INF) {
      d[i] = -1;
    }
  }
  return d;
}