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
  string S;
  cin >> S;
  vector<vector<int>> pos(2);
  for (int i = 0; i < N; i++) {
    if (S[i] == 'o') {
      pos[0].push_back(i);
    } else {
      pos[1].push_back(i);
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    int t = S[i] == 'o' ? 0 : 1;
    auto j = upper_bound(all(pos[t ^ 1]), i);
    if (j != pos[t ^ 1].end()) {
      ans += N - *j;
    }
  }
  cout << ans << endl;
}