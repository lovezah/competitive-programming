#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<vector<int>> pos(26);
  for (int i = 0; i < N; i++) {
    pos[S[i] - 'a'].push_back(i);
  }
  int ptr = -1;
  string ans;
  for (int k = 0; k < K; k++) {
    for (int c = 0; c < 26; c++) {
      if (pos[c].empty()) {
        continue;
      }
      auto it = upper_bound(all(pos[c]), ptr);
      if (it != pos[c].end() && *it + K - k - 1 < N) {
        ans.push_back(char('a' + c));
        ptr = *it;
        break;
      }
    }
  }
  cout << ans << endl;
}