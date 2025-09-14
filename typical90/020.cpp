#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c;
  cin >> a >> b >> c;
  ll d = 1;
  for (int i = 0; i < b; i++) {
    d *= c;
  }
  if (a < d) {
    cout << "Yes" << nl;
  } else {
    cout << "No" << nl;
  }
}