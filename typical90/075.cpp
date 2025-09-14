#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  map<ll, ll> mem;
  const ll INF = 1ll << 60;
  auto f = [&](auto f, ll X) -> ll {
    if (mem.find(X) != mem.end()) {
      return mem[X];
    }
    ll ans = INF;
    for (ll i = 2; i * i <= X; i++) {
      if (X % i == 0) {
        ans = min(ans, max(f(f, X / i), f(f, i)) + 1);
      }
    }
    if (ans == INF) {
      ans = 0;
    }
    return mem[X] = ans;
  };
  cout << f(f, N) << endl;
}