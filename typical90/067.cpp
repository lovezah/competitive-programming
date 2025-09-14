#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string N;
  int K;
  cin >> N >> K;
  while (K--) {
    ll A = 0;
    for (int i = 0; i < sz(N); i++) {
      A = A * 8 + (N[i] - '0');
    }
    if (A == 0) {
      N = "0";
    } else {
      string res;
      while (A > 0) {
        res = char(A % 9 + '0') + res;
        A /= 9;
      }
      N = res;
    }
    for (int i = 0; i < sz(N); i++) {
      if (N[i] == '8') {
        N[i] = '5';
      }
    }
  }
  cout << N << endl;
}