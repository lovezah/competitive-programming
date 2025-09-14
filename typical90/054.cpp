#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
template <typename T, typename U>
bool ckmin(T &a, const U &b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename U>
bool ckmax(T &a, const U &b) {
  return a < b ? a = b, true : false;
}
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> E(N + M);
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;
    vector<int> V(K);
    for (int j = 0; j < K; j++) {
      cin >> V[j];
      V[j]--;
    }
    for (int v : V) {
      E[v].emplace_back(N, 1);
      E[N].emplace_back(v, 0);
    }
    N++;
  }
  assert(N == sz(E));
  auto ans = dijkstra<ll>(E);
  for (int i = 0; i < N - M; i++) {
    cout << ans[i] << nl;
  }
}