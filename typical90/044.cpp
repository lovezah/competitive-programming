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
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int off = 0;
  while (Q--) {
    int T, x, y;
    cin >> T >> x >> y;
    if (T == 1) {
      x--;
      y--;
      x = (x + off) % N;
      y = (y + off) % N;
      swap(A[x], A[y]);
    } else if (T == 2) {
      off = (off + N - 1) % N;
    } else {
      x--;
      x = (x + off) % N;
      cout << A[x] << nl;
    }
  }
}