template <typename T, typename U>
bool ckmin(T &a, const U &b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename U>
bool ckmax(T &a, const U &b) {
  return a < b ? a = b, true : false;
}