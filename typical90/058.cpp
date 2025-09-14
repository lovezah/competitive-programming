#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
const int MAX = 100000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  ll K;
  cin >> K;
  auto get_sum = [&](int S) -> int {
    int sum = 0;
    while (S > 0) {
      sum += S % 10;
      S /= 10;
    }
    return sum;
  };
  vector<int> A(MAX, -1);
  A[N] = 0;
  int cnt = 1;
  while (K > 0) {
    int sum = get_sum(N);
    int N2 = (N + sum) % MAX;
    if (A[N2] != -1) {
      int C = cnt - A[N2];
      K %= C;
      break;
    }
    K--;
    N = N2;
    A[N2] = cnt++;
  }
  if (K > 0) {
    for (int i = 0; i < K; i++) {
      N = (N + get_sum(N)) % MAX;
    }
  }
  cout << N << endl;
}