#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vd = vector<db>;
using vl = vector<ll>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vpl = vector<pl>;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define ROF(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define R0F(i, n) ROF(i, 0, n)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a, x)

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
