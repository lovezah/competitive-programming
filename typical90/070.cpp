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
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  auto f = [&](vector<int> A) -> ll {
    sort(all(A));
    ll res = 0;
    for (int i = 0; i < N; i++) {
      res += abs(A[i] - A[N / 2]);
    }
    return res;
  };
  cout << f(X) + f(Y) << endl;
}