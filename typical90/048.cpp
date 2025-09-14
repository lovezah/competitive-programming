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
  vector<int> X;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    X.push_back(B);
    X.push_back(A - B);
  }
  sort(all(X));
  reverse(all(X));
  cout << accumulate(X.begin(), X.begin() + K, 0ll) << endl;
}