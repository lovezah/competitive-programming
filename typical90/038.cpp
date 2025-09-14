#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll A, B;
  cin >> A >> B;
  ll g = gcd(A, B);
  A /= g;
  if (__int128(A) * B > 1000000000000000000ll) {
    cout << "Large" << nl;
  } else {
    cout << A * B << nl;
  }
}