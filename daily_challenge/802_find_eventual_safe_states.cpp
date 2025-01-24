class Solution {
  vector<bool> visit, terminal;
  vector<int> mem;

public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    const size_t n = graph.size();
    terminal.resize(n);
    visit.resize(n);
    mem.resize(n, -1);

    for (int i = 0; i < n; i++)
      if (graph[i].empty())
        terminal[i] = true;

    vector<int> inner;
    for (int i = 0; i < n; i++) {
      if (dfs(graph, i))
        inner.push_back(i);
    }
    return inner;
  }

private:
  bool dfs(vector<vector<int>> &graph, int i) {
    if (i >= graph.size() || visit[i])
      return false;
    if (terminal[i])
      return true;
    if (mem[i] != -1)
      return mem[i];
    visit[i] = true;
    for (const auto &node : graph[i]) {
      if (!dfs(graph, node)) {
        visit[i] = false;
        return mem[i] = 0;
      }
    }
    visit[i] = false;
    return mem[i] = 1;
  }
};
