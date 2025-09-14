#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  deque<int> Q;
  int T;
  cin >> T;
  while (T--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      Q.push_front(x);
    } else if (t == 2) {
      Q.push_back(x);
    } else {
      cout << Q[x - 1] << nl;
    }
  }
}