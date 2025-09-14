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
  vector<int> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(all(A));
  int ans = N;
  for (int i = 0; i * A[2] <= N && i < 10000; i++) {
    for (int j = 0; i * A[2] + j * A[1] <= N && i + j < 10000; j++) {
      int remain = N - i * A[2] - j * A[1];
      if (remain == 0) {
        ans = min(ans, i + j);
      } else if (remain % A[0] == 0) {
        ans = min(ans, i + j + remain / A[0]);
      }
    }
  }
  cout << ans << endl;
}