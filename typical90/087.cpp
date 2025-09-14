#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, P, K;
  cin >> N >> P >> K;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  auto eval = [&](int X) -> int {
    const ll INF = 1ll << 59;
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) {
          dist[i][j] = 0;
        } else if (A[i][j] != -1) {
          dist[i][j] = A[i][j];
        } else if (X != -1) {
          dist[i][j] = X;
        }
      }
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (dist[i][j] <= P) {
          cnt++;
        }
      }
    }
    return cnt;
  };
  if (eval(-1) == K) {
    cout << "Infinity" << endl;
    return 0;
  }
  int l1;
  {
    int low = 0, high = 1e9;
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if (eval(mid) < K) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    l1 = low;
  }
  int l2;
  {
    int low = 0, high = 1e9;
    while (low < high) {
      int mid = (low + high + 1) / 2;
      if (eval(mid) <= K) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    l2 = low;
  }
  if (eval(l1) != K) {
    cout << 0 << endl;
  } else {
    cout << max(0, l1 - l2) << endl;
  }
}