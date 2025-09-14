#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
vector<int> LIS(const vector<int>& a) {
  int n = int(a.size());
  vector<int> dp(n);
  vector<int> b(n + 1, n + 1);
  b[0] = -1;
  for (int i = 0; i < n; i++) {
    int l = 0, r = i;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (b[m] < a[i]) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    dp[i] = l + 1;
    b[dp[i]] = min(b[dp[i]], a[i]);
  }
  return dp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> pref = LIS(A);
  reverse(all(A));
  vector<int> suff = LIS(A);
  int ans = 1;
  for (int i = 0; i < N; i++) {
    ans = max(ans, pref[i] + suff[N - 1 - i] - 1);
  }
  cout << ans << endl;
}