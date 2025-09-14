#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B[i][j];
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] != B[i][j]) {
        if (i == N - 1 || j == M - 1) {
          cout << "No" << endl;
          return 0;
        } else {
          int d = B[i][j] - A[i][j];
          A[i][j] += d;
          A[i + 1][j] += d;
          A[i][j + 1] += d;
          A[i + 1][j + 1] += d;
          ans += abs(d);
        }
      }
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
}