#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, D;
  cin >> N >> D;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll ans = 1ll << D;
  for (int mask = 1; mask < 1 << N; mask++) {
    int cnt = __builtin_popcount(mask);
    ll res = 0;
    for (int i = 0; i < N; i++) {
      if (mask >> i & 1) {
        res |= A[i];
      }
    }
    int c = 0;
    for (int j = 0; j < D; j++) {
      if (!(res >> j & 1)) {
        c++;
      }
    }
    if (cnt % 2 == 0) {
      ans += 1ll << c;
    } else {
      ans -= 1ll << c;
    }
  }
  cout << ans << endl;
}