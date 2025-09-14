#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  int cnt = 0;
  int j = 0;
  map<int, int> freq;
  for (int i = 0; i < N; i++) {
    freq[A[i]]++;
    if (freq[A[i]] == 1) {
      cnt++;
    }
    while (cnt > K) {
      freq[A[j]]--;
      if (freq[A[j]] == 0) {
        cnt--;
      }
      j++;
    }
    ans = max(ans, i - j + 1);
  }
  cout << ans << endl;
}