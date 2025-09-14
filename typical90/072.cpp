#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  int ans = -1;
  const vector<int> dxy = {1, 0, -1, 0, 1};
  vector<vector<bool>> used(N, vector<bool>(M));
  auto valid = [&](int x, int y) -> bool { return 0 <= x && x < N && 0 <= y && y < M; };
  auto dfs = [&](auto& dfs, int x, int y, int cnt, int sx, int sy) -> void {
    for (int i = 0; i < 4; i++) {
      int nx = x + dxy[i];
      int ny = y + dxy[i + 1];
      if (valid(nx, ny) && S[nx][ny] == '.' && !used[nx][ny]) {
        used[nx][ny] = true;
        dfs(dfs, nx, ny, cnt + 1, sx, sy);
        used[nx][ny] = false;
      }
      if (valid(nx, ny) && nx == sx && ny == sy && cnt >= 3) {
        ans = max(ans, cnt + 1);
      }
    }
  };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == '.') {
        used[i][j] = true;
        dfs(dfs, i, j, 0, i, j);
        used[i][j] = false;
      }
    }
  }
  cout << ans << endl;
}