class Solution {
#define ALPHA_SIZE 26
  vector<stack<int>> alpha;
  vector<vector<int>> adj;
  vector<int> out;

public:
  vector<int> findSubtreeSizes(vector<int> &parent, string s) {
    size_t n = parent.size();
    adj.resize(n);
    for (size_t i = 1; i < n; i++) {
      adj[parent[i]].push_back(i);
    }
    alpha.resize(ALPHA_SIZE);
    dfs(parent, 0, s);
    adj.clear();
    adj.resize(n);
    for (size_t i = 1; i < n; i++) {
      adj[parent[i]].push_back(i);
    }
    out.resize(n, 1);
    dfs2(0);
    return out;
  }

private:
  int dfs2(int i) {
    for (const auto &x : adj[i]) {
      out[i] += dfs2(x);
    }
    return out[i];
  }
  void dfs(vector<int> &parent, int i, string &s) {
    int index = s[i] - 'a';

    if (!alpha[index].empty()) {
      parent[i] = alpha[index].top();
    }

    alpha[index].push(i);

    for (const auto &x : adj[i]) {
      dfs(parent, x, s);
    }
    // node cannot be assined to sibling or lower nodes
    alpha[index].pop();
  }
};
