#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  const int MAX = 1001;
  vector<vector<int>> cnt(MAX, vector<int>(MAX, 0));
  for (int i = 0; i < N; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    cnt[lx][ly]++;
    cnt[lx][ry]--;
    cnt[rx][ly]--;
    cnt[rx][ry]++;
  }
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (i > 0) {
        cnt[i][j] += cnt[i - 1][j];
      }
      if (j > 0) {
        cnt[i][j] += cnt[i][j - 1];
      }
      if (i > 0 && j > 0) {
        cnt[i][j] -= cnt[i - 1][j - 1];
      }
    }
  }
  vector<int> ans(N + 1);
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (0 < cnt[i][j] && cnt[i][j] <= N) {
        ans[cnt[i][j]]++;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << nl;
  }
}