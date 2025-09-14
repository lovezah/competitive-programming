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
  ll P, Q;
  cin >> N >> P >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<ll>> B(N, vector<ll>(N));
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      B[i][j] = A[i] * A[j] % P;
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          for (int p = l + 1; p < N; p++) {
            ll now = A[i] * A[j] % P * A[k] % P * A[l] % P * A[p] % P;
            if (now == Q) {
              ans++;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}