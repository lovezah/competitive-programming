#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].emplace_back(b, c);
    E[b].emplace_back(a, c);
  }
  const ll INF = 1ll << 60;
  auto dijkstra = [&](int r) -> vector<ll> {
    vector<ll> d(N, INF);
    d[r] = 0;
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.emplace(d[r], r);
    while (!pq.empty()) {
      auto [cd, v] = pq.top();
      pq.pop();
      if (d[v] < cd) continue;
      for (auto [to, cost] : E[v]) {
        if (d[to] > d[v] + cost) {
          d[to] = d[v] + cost;
          pq.emplace(d[to], to);
        }
      }
    }
    return d;
  };
  auto d1 = dijkstra(0);
  auto dN = dijkstra(N - 1);
  for (int k = 0; k < N; k++) {
    cout << d1[k] + dN[k] << nl;
  }
}