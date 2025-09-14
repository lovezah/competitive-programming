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
  const int B = int(sqrt(M));
  vector<bool> big(N);
  for (int i = 0; i < N; i++) {
    if (sz(E[i]) > B) {
      big[i] = true;
    }
  }
  vector<vector<int>> bignei(N);
  for (int i = 0; i < N; i++) {
    for (int j : E[i]) {
      if (big[j]) {
        bignei[i].push_back(j);
      }
    }
  }
  vector<pair<int, int>> color(N);
  for (int i = 0; i < N; i++) {
    color[i] = make_pair(1, -1);
  }
  vector<pair<int, int>> change(N);
  for (int i = 0; i < N; i++) {
    if (big[i]) {
      change[i] = make_pair(1, -1);
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    if (big[x]) {
      cout << color[x].first << nl;
      color[x] = make_pair(y, i);
      for (int bn : bignei[x]) {
        color[bn] = color[x];
      }
      change[x] = color[x];
    } else {
      for (int bn : bignei[x]) {
        if (change[bn].second > color[x].second) {
          color[x] = change[bn];
        }
      }
      cout << color[x].first << nl;
      color[x] = make_pair(y, i);
      for (int n : E[x]) {
        color[n] = color[x];
      }
    }
  }
}