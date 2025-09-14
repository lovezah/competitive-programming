#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  ll gap = 0;
  for (int i = 0; i < N; i++) {
    gap += abs(A[i] - B[i]);
  }
  if (gap <= K && (K - gap) % 2 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}