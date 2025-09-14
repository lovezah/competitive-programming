#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using views::iota;
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> A(N);
  for (int i : iota(0, N)) {
    cin >> A[i].first >> A[i].second;
  }
  vector<pair<int, int>> B(N);
  for (int i : iota(0, N)) {
    cin >> B[i].first >> B[i].second;
  }
  sort(all(B));
  const vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
  const vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
  auto find = [&](int x, int y, int d) -> pair<int, int> {
    int nx = x + dx[d] * T;
    int ny = y + dy[d] * T;
    return make_pair(nx, ny);
  };
  matching E(N, N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 8; j++) {
      auto [nx, ny] = find(A[i].first, A[i].second, j);
      auto it = lower_bound(all(B), make_pair(nx, ny));
      if (it != B.end() && it->first == nx && it->second == ny) {
        int p = it - B.begin();
        E.add_edge(i, p);
      }
    }
  }
  int cnt = E.solve();
  if (cnt == N) {
    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
      int who = E.A[i];
      for (int j = 0; j < 8; j++) {
        auto pos = find(A[i].first, A[i].second, j);
        if (pos == B[who]) {
          cout << j + 1 << " ";
          break;
        }
      }
    }
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}