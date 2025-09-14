#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
struct UnionFind {
  int cnt = 0;
  vector<int> p;
  UnionFind(int n) {
    p = vector<int>(n, -1);
    cnt = n;
  }
  int root(int x) {
    if (p[x] < 0) {
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
      cnt--;
      return true;
    } else {
      return false;
    }
  }
};
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
  int N;
  cin >> N;
  UnionFind UF(N);
  FenwickTree<ll> fen(N - 1);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int T, X, Y, V;
    cin >> T >> X >> Y >> V;
    X--;
    Y--;
    if (T == 0) {
      assert(X + 1 == Y);
      if (UF.unite(X, Y)) {
        if (X % 2 == 0) {
          fen.add(X, -V);
        } else {
          fen.add(X, V);
        }
      }
    }
    if (T == 1) {
      if (!UF.same(X, Y)) {
        cout << "Ambiguous" << nl;
        continue;
      }
      ll ans = 0;
      if (X == Y) {
        ans = V;
      } else if (X < Y) {
        ll gap = fen.sum(X, Y);
        if (X % 2 == 0) {
          gap *= -1;
        }
        if (X % 2 == Y % 2) {
          ans = (ll)V - gap;
        } else {
          ans = (ll)gap - V;
        }
      } else {
        ll gap = fen.sum(Y, X);
        if (Y % 2 == 0) {
          gap *= -1;
        }
        if (Y % 2 == X % 2) {
          ans = (ll)gap + V;
        } else {
          ans = (ll)gap - V;
        }
      }
      cout << ans << nl;
    }
  }
}