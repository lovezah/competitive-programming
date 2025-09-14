vector<int> minp;
vector<int> primes;
void sieve(int N) {
  minp.assign(N + 1, 0);
  primes.clear();
  for (int i = 2; i <= N; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > N) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        break;
      }
    }
  }
}
bool isprime(int x) { return minp[x] == x; }