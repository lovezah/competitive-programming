#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, S;
  cin >> N >> S;
  vector<bool> dp(S + 1);
  dp[0] = true;
  vector<vector<int>> status(N, vector<int>(S + 1, -1));
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    vector<bool> ndp(S + 1);
    for (int j = 0; j < S; j++) {
      if (dp[j]) {
        if (j + A[i] <= S) {
          ndp[j + A[i]] = true;
          status[i][j + A[i]] = 0;
        }
        if (j + B[i] <= S) {
          ndp[j + B[i]] = true;
          status[i][j + B[i]] = 1;
        }
      }
    }
    dp = ndp;
  }
  if (!dp.back()) {
    cout << "Impossible" << nl;
  } else {
    int cur = S;
    int ptr = N - 1;
    string ans;
    while (ptr >= 0) {
      if (status[ptr][cur] == 0) {
        ans.push_back('A');
        cur -= A[ptr];
      } else {
        ans.push_back('B');
        cur -= B[ptr];
      }
      ptr--;
    }
    reverse(all(ans));
    cout << ans << nl;
  }
}