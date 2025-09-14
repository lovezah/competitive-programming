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