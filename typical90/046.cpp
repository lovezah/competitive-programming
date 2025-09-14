#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> cnt(3, vector<int>(46));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      a %= 46;
      cnt[i][a]++;
    }
  }
  ll ans = 0;
  for (int i = 0; i < 46; i++) {
    for (int j = 0; j < 46; j++) {
      for (int k = 0; k < 46; k++) {
        if ((i + j + k) % 46 == 0) {
          ans += (ll)cnt[0][i] * cnt[1][j] * cnt[2][k];
        }
      }
    }
  }
  cout << ans << endl;
}