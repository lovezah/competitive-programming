const long long MOD = 998244353;
long long modpow(long long a, long long k) {
  long long r = 1;
  while (k > 0) {
    if (k & 1) {
      r = r * a % MOD;
    }
    a = a * a % MOD;
    k /= 2;
  }
  return r;
}
long long modinv(long long a) { return modpow(a, MOD - 2); }
vector<long long> fact(1, 1);
vector<long long> ifact(1, 1);
long long binom(int a, int b) {
  if (a < b || b < 0) {
    return 0;
  }
  if (fact.size() <= a) {
    int n = fact.size();
    int m = n;
    while (m <= a) {
      m *= 2;
    }
    fact.resize(m);
    for (int i = n; i < m; i++) {
      fact[i] = fact[i - 1] * i % MOD;
    }
    ifact.resize(m);
    ifact[m - 1] = modinv(fact[m - 1], MOD - 2);
    for (int i = m - 1; i > n; i--) {
      ifact[i - 1] = ifact[i] * i % MOD;
    }
  }
  return fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}