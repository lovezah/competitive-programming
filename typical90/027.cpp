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
  map<string, bool> seen;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (seen.find(S) == seen.end()) {
      cout << i + 1 << nl;
      seen[S] = true;
    }
  }
}