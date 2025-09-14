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
  FenwickTree(int _n) : n(_n) { f.assign(_n, T()); }
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
  int N, M;
  cin >> N >> M;
  vector<int> L(M), R(M);
  for (int i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  vector<int> freq(N);
  for (int i = 0; i < M; i++) {
    freq[L[i]]++;
    freq[R[i]]++;
  }
  ll ans = (ll)M * (M - 1) / 2;
  for (int i = 0; i < N; i++) {
    ans -= (ll)freq[i] * (freq[i] - 1) / 2;
  }
  vector<int> order(M);
  iota(all(order), 0);
  sort(all(order), [&](int i, int j) { return L[i] < L[j]; });
  FenwickTree<ll> FT(N);
  for (int i : order) {
    ans -= FT.sum(L[i]);
    FT.add(R[i], 1);
  }
  int cur_l = -1;
  vector<int> add;
  FT = FenwickTree<ll>(N);
  for (int i : order) {
    if (L[i] != cur_l) {
      for (int v : add) {
        FT.add(v, 1);
      }
      add.clear();
      cur_l = L[i];
    }
    if (L[i] == cur_l) {
      add.push_back(R[i]);
    }
    ans -= FT.sum(R[i] + 1, N);
  }
  cout << ans << endl;
}