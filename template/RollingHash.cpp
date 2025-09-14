mt19937_64 mt(random_device{}());
long long rng(long long v) { return mt() % v; }
using hash_t = array<long long, 2>;
const hash_t hash_mod = {1000000007, 1000000009};
const hash_t base = {23333, 12223};
hash_t operator+(const hash_t &a, const hash_t &b) {
  hash_t res;
  for (int i = 0; i < 2; i++) {
    res[i] = (a[i] + b[i]) % hash_mod[i];
  }
  return res;
}
hash_t operator-(const hash_t &a, const hash_t &b) {
  hash_t res;
  for (int i = 0; i < 2; i++) {
    res[i] = (a[i] - b[i] + hash_mod[i]) % hash_mod[i];
  }
  return res;
}
hash_t operator*(const hash_t &a, const hash_t &b) {
  hash_t res;
  for (int i = 0; i < 2; i++) {
    res[i] = a[i] * b[i] % hash_mod[i];
  }
  return res;
}
vector<hash_t> hash_pow{{1, 1}};
void hash_expend(int m) {
  int n = (int)hash_pow.size();
  if (m > n) {
    hash_pow.resize(m);
    for (int i = n; i < m; i++) {
      hash_pow[i] = hash_pow[i - 1] * base;
    }
  }
}
vector<hash_t> hash_sig(128, {-1, -1});
struct RollingHash {
  vector<hash_t> h;
  template <typename T>
  RollingHash(const vector<T> &s) {
    int n = (int)s.size();
    h.assign(n + 1, {0, 0});
    hash_expend(n + 1);
    for (int i = 0; i < n; i++) {
      if (hash_sig[s[i]] == hash_t{-1, -1}) {
        hash_sig[s[i]] = {rng(hash_mod[0]), rng(hash_mod[1])};
      }
      h[i + 1] = h[i] * base + hash_sig[s[i]];
    }
  }
  RollingHash(const string &s)
      : RollingHash(vector<char>(s.begin(), s.end())) {}
  hash_t get(int l, int r) { return h[r] - h[l] * hash_pow[r - l]; }
};