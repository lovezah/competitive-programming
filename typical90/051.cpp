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
  ll P;
  cin >> N >> K >> P;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int N1 = N / 2, N2 = N - N1;
  vector<ll> L(N1), R(N2);
  for (int i = 0; i < N1; i++) {
    L[i] = A[i];
  }
  for (int i = 0; i < N2; i++) {
    R[i] = A[N1 + i];
  }
  ll ans = 0;
  vector<vector<ll>> dp(N1 + 1);
  for (int i = 0; i < 1 << N1; i++) {
    int cnt = __builtin_popcount(i);
    ll tot = 0;
    for (int j = 0; j < N1; j++) {
      if (i >> j & 1) {
        tot += L[j];
      }
    }
    dp[cnt].push_back(tot);
    if (cnt == K && tot <= P) {
      ans++;
    }
  }
  for (int i = 1; i <= N1; i++) {
    sort(all(dp[i]));
  }
  assert(N1 + N2 == N);
  for (int i = 1; i < 1 << N2; i++) {
    int cnt = __builtin_popcount(i);
    ll tot = 0;
    for (int j = 0; j < N2; j++) {
      if (i >> j & 1) {
        tot += R[j];
      }
    }
    if (cnt == K && tot <= P) {
      ans++;
    }
    if (cnt < K) {
      ll rem = P - tot;
      if (rem > 0 && 0 < K - cnt && K - cnt <= N1) {
        int add = upper_bound(all(dp[K - cnt]), rem) - dp[K - cnt].begin();
        ans += add;
      }
    }
  }
  cout << ans << endl;
}