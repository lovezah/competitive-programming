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
  vector<vector<int>> A(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    int T;
    cin >> T;
    for (int j = 0; j < T; j++) {
      int c;
      cin >> c;
      c--;
      A[i][c] = 1;
    }
  }
  vector<int> S(M);
  for (int i = 0; i < M; i++) {
    cin >> S[i];
  }
  int rank = 0;
  for (int i = 0; i < M; i++) {
    bool found = false;
    for (int j = rank; j < N; j++) {
      if (A[j][i] == 1) {
        if (j != rank) {
          swap(A[j], A[rank]);
        }
        found = true;
      }
    }
    if (found) {
      for (int j = 0; j < N; j++) {
        if (j != rank && A[j][i] == 1) {
          for (int k = i; k < M; k++) {
            A[j][k] ^= A[rank][k];
          }
        }
      }
      if (S[i] == 1) {
        for (int j = i; j < M; j++) {
          S[j] ^= A[rank][j];
        }
      }
      rank += 1;
    }
  }
  int ans = 0;
  if (S == vector<int>(M, 0)) {
    ans = 1;
    for (int i = rank; i < N; i++) {
      ans = ans * 2 % 998244353;
    }
  }
  cout << ans << endl;
}