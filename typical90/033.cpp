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
  vector<vector<bool>> A(N, vector<bool>(M));
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      bool good = true;
      if (i > 0 && j > 0) {
        good = good && !A[i - 1][j - 1] && !A[i - 1][j] && !A[i][j - 1];
      }
      if (i > 0 && j < M - 1) {
        good = good && !A[i - 1][j] && !A[i - 1][j + 1] && !A[i][j + 1];
      }
      if (i < N - 1 && j > 0) {
        good = good && !A[i][j - 1] && !A[i + 1][j - 1] && !A[i + 1][j];
      }
      if (i < N - 1 && j < M - 1) {
        good = good && !A[i][j + 1] && !A[i + 1][j] && !A[i + 1][j + 1];
      }
      if (good) {
        A[i][j] = true;
        ans++;
      }
    }
  }
  cout << ans << endl;
}