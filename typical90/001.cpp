#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, L;
  cin >> N >> L;
  int K;
  cin >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int low = 1, high = L;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    int lst = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] - lst >= mid) {
        lst = A[i];
        cnt++;
        if (cnt == K) break;
      }
    }
    if (L - lst < mid || cnt < K) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low << endl;
}