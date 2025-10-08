#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;

using vi = vector<int>;
using vd = vector<ld>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a) for (int i = 0; i < (a); i++)
#define FORa(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define FORda(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define trav(a, x) for (auto a : (x))

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

template <class T, class U> bool ckmin(T &a, const U b) { return b < a ? a = b, true : false; }
template <class T, class U> bool ckmax(T &a, const U b) { return b > a ? a = b, true : false; }

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif

template <typename T> T mod_inv_in_range(T a, T m) {
  // assert(0 <= a && a < m);
  T x = a, y = m;
  // coeff of a in x and y
  T vx = 1, vy = 0;
  while (x) {
    T k = y / x;
    y %= x;
    vy -= k * vx;
    std::swap(x, y);
    std::swap(vx, vy);
  }
  assert(y == 1);
  return vy < 0 ? m + vy : vy;
}
template <typename T> struct extended_gcd_result {
  T gcd;
  T coeff_a, coeff_b;
};
template <typename T> extended_gcd_result<T> extended_gcd(T a, T b) {
  T x = a, y = b;
  // coeff of a and b in x and y
  T ax = 1, ay = 0;
  T bx = 0, by = 1;
  while (x) {
    T k = y / x;
    y %= x;
    ay -= k * ax;
    by -= k * bx;
    std::swap(x, y);
    std::swap(ax, ay);
    std::swap(bx, by);
  }
  return {y, ay, by};
}
template <typename T> T mod_inv(T a, T m) {
  a %= m;
  a = a < 0 ? a + m : a;
  return mod_inv_in_range(a, m);
}
template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  int v;

public:
  modnum() : v(0) {}
  modnum(int64_t v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream &operator<<(std::ostream &out, const modnum &n) { return out << int(n); }
  friend std::istream &operator>>(std::istream &in, modnum &n) {
    int64_t v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum &a, const modnum &b) { return a.v == b.v; }
  friend bool operator!=(const modnum &a, const modnum &b) { return a.v != b.v; }
  modnum inv() const {
    modnum res;
    res.v = mod_inv_in_range(v, MOD);
    return res;
  }
  friend modnum inv(const modnum &m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum &m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum &operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum &operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum &operator+=(const modnum &o) {
    v -= MOD - o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = int(int64_t(v) * int64_t(o.v) % MOD);
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= o.inv(); }
  friend modnum operator++(modnum &a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum &a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum &a, const modnum &b) { return modnum(a) += b; }
  friend modnum operator-(const modnum &a, const modnum &b) { return modnum(a) -= b; }
  friend modnum operator*(const modnum &a, const modnum &b) { return modnum(a) *= b; }
  friend modnum operator/(const modnum &a, const modnum &b) { return modnum(a) /= b; }
};
template <typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}
using num = modnum<998244353>;
// using num = modnum<int(1e9) + 7>;

vector<num> fact, ifact;
bool FACT_INIT = false;
void init() {
  FACT_INIT = true;
  int N = 4.1e5;
  fact.resize(N);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
  }
  ifact.resize(N);
  ifact.back() = 1 / fact.back();
  for (int i = N - 1; i > 0; i--) {
    ifact[i - 1] = ifact[i] * i;
  }
}
num ncr(int n, int k) {
  assert(FACT_INIT);
  if (k < 0 || k > n) {
    return 0;
  } else {
    return fact[n] * ifact[k] * ifact[n - k];
  }
}

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  cout << setprecision(20);
  init();
  int R, G, B, K;
  cin >> R >> G >> B >> K;
  int X, Y, Z;
  cin >> X >> Y >> Z;
}