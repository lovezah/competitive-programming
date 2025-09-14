#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N + N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i + N] = A[i];
  }
  vector<ll> pref(N + N + 1);
  for (int i = 0; i < N + N; i++) {
    pref[i + 1] = pref[i] + A[i];
  }
  for (int i = 0; i < N; i++) {
    int low = i, high = i + N - 1;
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if ((pref[mid + 1] - pref[i]) * 10 > pref[N]) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    if ((pref[low + 1] - pref[i]) * 10 == pref[N]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}