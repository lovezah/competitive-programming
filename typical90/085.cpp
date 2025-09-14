#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll K;
  cin >> K;
  ll ans = 0;
  for (ll a = 1; a <= 10000; a++) {
    if (K % a != 0) {
      continue;
    }
    ll bc = K / a;
    vector<ll> divs;
    for (ll i = 1; i * i <= bc; i++) {
      if (bc % i == 0) {
        divs.push_back(i);
        if (bc / i != i) {
          divs.push_back(bc / i);
        }
      }
    }
    sort(all(divs));
    divs.erase(unique(all(divs)), divs.end());
    for (ll b : divs) {
      ll c = bc / b;
      if (a <= b && b <= c && a * b * c == K) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}