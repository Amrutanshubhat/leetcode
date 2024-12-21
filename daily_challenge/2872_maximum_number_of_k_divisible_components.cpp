class Solution {
  vector<vector<int>> adj;
  vector<int> *p;
  vector<bool> visit;
  size_t components = 0;

public:
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    adj.resize(n);
    visit.resize(n);
    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    this->p = &values;
    dfs(0, k);
    return components;
  }

private:
  int dfs(int val, int k) {
    if (visit[val])
      return 0;
    visit[val] = true;

    long tot = ((*p)[val]) % k;
    for (const auto &node : adj[val]) {
      tot = ((dfs(node, k) % k) + tot) % k;
    }
    if (tot)
      return tot;
    components++;
    return 0;
  }
};
