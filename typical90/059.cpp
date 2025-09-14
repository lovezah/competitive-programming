#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<pair<int, int>> edges(M);
  for (auto& [a, b] : edges) {
    cin >> a >> b;
    a--;
    b--;
  }
  sort(all(edges));
  vector<int> A(Q), B(Q);
  for (int i = 0; i < Q; i++) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  using ull = unsigned long long;
  for (int i = 0; i < Q; i += 64) {
    vector<ull> dp(N);
    for (int j = 0; j < 64 && i + j < Q; j++) {
      dp[A[i + j]] |= 1ull << j;
    }
    for (auto [a, b] : edges) {
      dp[b] |= dp[a];
    }
    for (int j = 0; j < 64 && i + j < Q; j++) {
      if (dp[B[i + j]] >> j & 1) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
    }
  }
}