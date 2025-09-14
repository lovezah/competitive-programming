#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
const double PI = acos(-1);
double SQ(double A) { return A * A; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int L, X, Y;
  cin >> L >> X >> Y;
  int tt;
  cin >> tt;
  while (tt--) {
    int E;
    cin >> E;
    double angle = (double)270 - ((double)E / T) * 360;
    angle = angle * PI / 180;
    double P = cos(angle) * L / 2;
    double Q = sin(angle) * L / 2;
    Q += (double)L / 2;
    // (0,P,Q) -> (X,Y,0)
    double DZ = Q;
    double DI = sqrt(SQ(0 - X) + SQ(P - Y) + SQ(Q - 0));
    double nangle = asin(DZ / DI);
    nangle = nangle * 180 / PI;
    cout << fixed << setprecision(10) << nangle << nl;
  }
}