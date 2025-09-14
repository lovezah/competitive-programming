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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  UnionFind UF(N * M);
  const int d[] = {0, 1, 0, -1, 0};
  int Q;
  cin >> Q;
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      if (A[r][c] == 0) {
        A[r][c] = 1;
        for (int i = 0; i < 4; i++) {
          int nr = r + d[i];
          int nc = c + d[i + 1];
          if (0 <= nr && nr < N && 0 <= nc && nc < M && A[nr][nc]) {
            UF.unite(r * M + c, nr * M + nc);
          }
        }
      }
    }
    if (t == 2) {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;
      ca--;
      rb--;
      cb--;
      if (A[ra][ca] && A[rb][cb] && UF.same(ra * M + ca, rb * M + cb)) {
        cout << "Yes" << nl;
      } else {
        cout << "No" << nl;
      }
    }
  }
}