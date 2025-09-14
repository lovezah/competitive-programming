vector<int> LIS(const vector<int>& a) {
  int n = int(a.size());
  vector<int> dp(n);
  vector<int> b(n + 1, n + 1);
  b[0] = -1;
  for (int i = 0; i < n; i++) {
    int l = 0, r = i;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (b[m] < a[i]) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    dp[i] = l + 1;
    b[dp[i]] = min(b[dp[i]], a[i]);
  }
  return dp;
}