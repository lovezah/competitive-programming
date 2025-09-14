#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
const int MAX = 5000;
vector<int> get_pref(vector<int> a) {
  int n = sz(a);
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  return pref;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
  }
  vector<vector<int>> height(MAX + 1);
  for (int i = 0; i < N; i++) {
    height[A[i].first].push_back(i);
  }
  int ans = 0;
  vector<int> weight(MAX);
  {
    for (int h = 0; h <= K; h++) {
      for (int who : height[h]) {
        assert(0 <= A[who].second && A[who].second < MAX);
        weight[A[who].second] += 1;
      }
    }
    auto pref = get_pref(weight);
    for (int i = K + 1; i <= MAX; i++) {
      ans = max(ans, pref[i] - pref[i - K - 1]);
    }
  }
  for (int max_h = K + 1; max_h < MAX; max_h++) {
    for (int who : height[max_h]) {
      assert(0 <= A[who].second && A[who].second < MAX);
      weight[A[who].second] += 1;
    }
    for (int who : height[max_h - K - 1]) {
      assert(0 <= A[who].second && A[who].second < MAX);
      weight[A[who].second] -= 1;
    }
    auto pref = get_pref(weight);
    for (int i = K + 1; i <= MAX; i++) {
      ans = max(ans, pref[i] - pref[i - K - 1]);
    }
  }
  cout << ans << endl;
}