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
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j : E[i]) {
      if (j < i) {
        cnt++;
      }
    }
    if (cnt == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}