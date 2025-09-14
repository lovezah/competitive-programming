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
  vector<string> ans;
  for (int i = 0; i < 1 << N; i++) {
    int bal = 0;
    bool ok = true;
    string cur;
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        bal++;
        cur.push_back('(');
      } else {
        bal--;
        cur.push_back(')');
      }
      if (bal < 0) {
        ok = false;
      }
    }
    if (bal != 0) {
      ok = false;
    }
    if (ok) {
      ans.push_back(cur);
    }
  }
  sort(all(ans));
  for (auto s : ans) {
    cout << s << nl;
  }
}