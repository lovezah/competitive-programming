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
