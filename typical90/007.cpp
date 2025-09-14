#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(all(A));
  const int INF = (int)1e9;
  int Q;
  cin >> Q;
  while (Q--) {
    int B;
    cin >> B;
    int ans = INF;
    auto it = lower_bound(all(A), B);
    if (it != A.end()) {
      ans = min(ans, abs(*it - B));
    }
    if (it != A.begin()) {
      it = prev(it);
      ans = min(ans, abs(*it - B));
    }
    cout << ans << nl;
  }
}