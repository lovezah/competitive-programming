#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> pref(2, vector<int>(N + 1));
  for (int i = 0; i < N; i++) {
    int C, P;
    cin >> C >> P;
    C--;
    pref[C][i + 1] = pref[C][i] + P;
    pref[C ^ 1][i + 1] = pref[C ^ 1][i];
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int L, R;
    cin >> L >> R;
    L--;
    for (int i = 0; i < 2; i++) {
      cout << pref[i][R] - pref[i][L] << " \n"[i == 1];
    }
  }
}