#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  vector<int> row(N), col(M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      row[i] += A[i][j];
      col[j] += A[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << row[i] + col[j] - A[i][j] << " \n"[j == M - 1];
    }
  }
}