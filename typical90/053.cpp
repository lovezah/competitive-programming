#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
const ll INF = 1ll << 40;
vector<int> fib;
void solve() {
  int N;
  cin >> N;
  vector<ll> A;
  auto query = [&](int x) -> ll {
    if (A[x] == -1) {
      cout << "? " << x << endl;
      ll v;
      cin >> v;
      A[x] = v;
    }
    return A[x];
  };
  for (int i = 0; i < sz(fib); i++) {
    if (fib[i] > N) {
      int M = fib[i];
      A.assign(M + 1, -1);
      A[0] = -INF;
      for (int j = N + 1; j <= M; j++) {
        if (j == N + 1) {
          A[j] = -INF;
        } else {
          A[j] = A[j - 1] - INF;
        }
      }
      int l = 0, r = M;
      for (int q = i; q >= 2; q--) {
        ll a = query(l + fib[q - 2]);
        ll b = query(r - fib[q - 2]);
        if (a < b) {
          l += fib[q - 2];
        } else {
          r -= fib[q - 2];
        }
        if (q == 2) {
          cout << "! " << max(a, b) << endl;
        }
      }
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fib.emplace_back(1);
  fib.emplace_back(1);
  while (fib.back() < 2000) {
    fib.emplace_back(fib.end()[-2] + fib.end()[-1]);
  }
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}