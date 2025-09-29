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

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  cout << setprecision(20);
  ${0}
}