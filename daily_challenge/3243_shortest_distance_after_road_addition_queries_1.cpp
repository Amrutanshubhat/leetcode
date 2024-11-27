class Solution {
  vector<vector<int>> conn;
  vector<int> d;
  queue<int> q;

public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    conn.resize(n);
    d.resize(n);

    // initially 1-1 connection
    for (size_t i = 0; i < n - 1; i++) {
      d[i] = i;
      conn[i].push_back(i + 1);
    }
    d[n - 1] = n - 1;

    vector<int> out;
    for (size_t i = 0; i < queries.size(); i++) {
      int f = queries[i][0], t = queries[i][1];
      conn[f].push_back(t);

      if (d[f] + 1 < d[t])
        bfs(f);

      out.push_back(d[n - 1]);
    }
    return out;
  }

private:
  void bfs(int node) {
    q.push(node);
    while (!q.empty()) {
      int val = q.front();
      q.pop();
      for (const auto &x : conn[val]) {
        if (d[val] + 1 < d[x]) {
          d[x] = d[val] + 1;
          q.push(x);
        }
      }
    }
  }
};
