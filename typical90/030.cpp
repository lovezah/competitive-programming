#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  sieve(N);
  int ans = 0;
  for (int i = 2; i <= N; i++) {
    int x = i;
    int last = -1;
    int cnt = 0;
    while (x > 1) {
      if (minp[x] != last) {
        last = minp[x];
        cnt++;
      }
      x /= minp[x];
      if (cnt >= K) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}