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
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<vector<int>> mem(51, vector<int>(3000, -1));
  auto get = [&](auto& self, int w, int b) -> int {
    if (mem[w][b] != -1) {
      return mem[w][b];
    }
    if (w == 0 && b < 2) {
      return mem[w][b] = 0;
    }
    set<int> mex;
    if (w >= 1) {
      mex.insert(self(self, w - 1, b + w));
    }
    if (b >= 2) {
      for (int i = 1; i <= b / 2; i++) {
        mex.insert(self(self, w, b - i));
      }
    }
    for (int v = 0; true; v++) {
      if (mex.count(v) == 0) {
        return mem[w][b] = v;
      }
    }
  };
  int grundy = 0;
  for (int i = 0; i < N; i++) {
    grundy ^= get(get, W[i], B[i]);
  }
  if (grundy == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}