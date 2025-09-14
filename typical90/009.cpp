#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
const double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  auto get_angle = [&](pair<int, int> C) -> double {
    double l = sqrt((ll)C.first * C.first + (ll)C.second * C.second);
    double ang = acos(C.first / l) / PI * 180.0;
    if (C.second < 0) {
      ang = 360.0 - ang;
    }
    return ang;
  };
  auto get_angle2 = [&](double a, double b) -> double {
    double I = abs(a - b);
    if (I >= 180) {
      I = 360 - I;
    }
    return I;
  };
  double ans = 0;
  for (int i = 0; i < N; i++) {
    vector<double> degree;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      pair<double, double> cur = make_pair(A[j].first - A[i].first, A[j].second - A[i].second);
      degree.emplace_back(get_angle(cur));
    }
    sort(all(degree));
    assert(sz(degree) == N - 1);
    for (auto d : degree) {
      double t = d + 180.0;
      if (t >= 360) {
        t -= 360;
      }
      auto j = lower_bound(all(degree), t) - degree.begin();
      auto k = (j - 1 + N - 1) % (N - 1);
      if (j == sz(degree)) {
        j = (j + 1) % (N - 1);
      }
      assert(0 <= j && j < sz(degree));
      assert(0 <= k && k < sz(degree));
      ans = max({ans, get_angle2(d, degree[j]), get_angle2(d, degree[k])});
    }
  }
  cout << setprecision(20);
  cout << ans << endl;
}