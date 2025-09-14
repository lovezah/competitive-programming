#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }
  double ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int tot = 0;
      for (int v = L[i]; v <= R[i]; v++) {
        if (L[j] < v) {
          int cnt = min(R[j], v - 1) - L[j] + 1;
          tot += cnt;
        }
      }
      ans += (double)tot / (R[i] - L[i] + 1) / (R[j] - L[j] + 1);
    }
  }
  cout << setprecision(10) << ans << endl;
}