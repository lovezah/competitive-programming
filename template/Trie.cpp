template <int sigma>
struct Trie {
  struct Node {
    array<int, sigma> ch;
    array<int, sigma> nxt;
    int par;
    int suffix_link;
  };
  int n_node;
  vector<Node> nodes;
  vector<int> words;
  vector<int> BFS;
  Trie() {
    n_node = 0;
    new_node();
  }
  int new_node() {
    Node c;
    fill(c.ch.begin(), c.ch.end(), -1);
    fill(c.nxt.begin(), c.nxt.end(), -1);
    c.par = -1;
    c.suffix_link = -1;
    nodes.emplace_back(c);
    return n_node++;
  }
  Node& operator[](int i) { return nodes[i]; }
  template <typename T>
  int add(T S, int off) {
    int p = 0;
    for (auto s : S) {
      p = add_single(p, s, off);
    }
    words.emplace_back(p);
    return p;
  }
  int add_single(int p, int c, int off) {
    c -= off;
    assert(0 <= c && c < sigma);
    if (nodes[p].ch[c] != -1) {
      return nodes[p].ch[c];
    }
    nodes[p].ch[c] = new_node();
    nodes.back().par = p;
    return nodes[p].ch[c];
  }
  void calc_suffix_link() {
    BFS.resize(n_node);
    int p = 0;
    BFS[p++] = 0;
    for (int i = 0; i < p; i++) {
      int u = BFS[i];
      for (int j = 0; j < sigma; j++) {
        int v = nodes[u].ch[j];
        if (v == -1) {
          if (u > 0) {
            nodes[u].nxt[j] = nodes[nodes[u].suffix_link].nxt[j];
          } else {
            nodes[u].nxt[j] = 0;
          }
        } else {
          nodes[u].nxt[j] = v;
          if (u > 0) {
            nodes[v].suffix_link = nodes[nodes[u].suffix_link].nxt[j];
          } else {
            nodes[v].suffix_link = 0;
          }
          BFS[p++] = v;
        }
      }
    }
  }
};