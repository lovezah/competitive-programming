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
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for (int mask = 1; mask < 1 << N; mask++) {
    vector<int> rows;
    for (int i = 0; i < N; i++) {
      if (mask >> i & 1) {
        rows.push_back(i);
      }
    }
    map<int, int> freq;
    for (int j = 0; j < M; j++) {
      bool ok = true;
      int v = A[rows.front()][j];
      for (int i : rows) {
        ok = ok && (v == A[i][j]);
        if (!ok) {
          break;
        }
      }
      if (ok) {
        freq[v] += 1;
      }
    }
    for (auto [v, c] : freq) {
      ans = max(ans, c * sz(rows));
    }
  }
  cout << ans << endl;
}