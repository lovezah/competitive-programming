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
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(all(A));
  sort(all(B));
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(A[i] - B[i]);
  }
  cout << ans << nl;
}