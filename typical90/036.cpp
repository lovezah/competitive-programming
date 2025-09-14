#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  for (int i = 0; i < N; i++) {
    ll x = X[i] - Y[i];
    ll y = X[i] + Y[i];
    X[i] = x;
    Y[i] = y;
  }
  ll max_x = *max_element(all(X));
  ll min_x = *min_element(all(X));
  ll max_y = *max_element(all(Y));
  ll min_y = *min_element(all(Y));
  for (int q = 0; q < Q; q++) {
    int i;
    cin >> i;
    i--;
    ll a = abs(max_x - X[i]);
    ll b = abs(min_x - X[i]);
    ll c = abs(max_y - Y[i]);
    ll d = abs(min_y - Y[i]);
    cout << max({a, b, c, d}) << nl;
  }
}