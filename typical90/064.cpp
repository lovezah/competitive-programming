#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
template <typename T>
struct FenwickTree {
  int n;
  vector<T> f;
  FenwickTree() {}
  FenwickTree(int n) : n(n) { f.assign(n, T()); }
  void add(int i, T x) {
    for (int j = i + 1; j <= n; j += j & -j) {
      f[j - 1] += x;
    }
  }
  T sum(int i) {
    T res = 0;
    for (int j = i; j > 0; j -= j & -j) {
      res += f[j - 1];
    }
    return res;
  }
  T sum(int i, int j) { return sum(j) - sum(i); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  FenwickTree<ll> fenw(N);
  fenw.add(0, A[0]);
  for (int i = 1; i < N; i++) {
    fenw.add(i, A[i] - A[i - 1]);
  }
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    ans += abs(A[i] - A[i - 1]);
  }
  while (Q--) {
    int L, R, V;
    cin >> L >> R >> V;
    L--;
    if (L > 0) {
      ans -= abs(fenw.sum(L + 1) - fenw.sum(L));
    }
    if (R < N) {
      ans -= abs(fenw.sum(R) - fenw.sum(R + 1));
    }
    fenw.add(L, V);
    if (R < N) {
      fenw.add(R, -V);
    }
    if (L > 0) {
      ans += abs(fenw.sum(L + 1) - fenw.sum(L));
    }
    if (R < N) {
      ans += abs(fenw.sum(R) - fenw.sum(R + 1));
    }
    cout << ans << nl;
  }
}