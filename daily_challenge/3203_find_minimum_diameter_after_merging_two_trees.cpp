class Solution {
public:
  int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                vector<vector<int>> &edges2) {
    unordered_map<int, vector<int>> adj1, adj2;

    {
      auto fill_adj = [](vector<vector<int>> &edges,
                         unordered_map<int, vector<int>> &adj) -> void {
        for (const auto &edge : edges) {
          adj[edge[0]].emplace_back(edge[1]);
          adj[edge[1]].emplace_back(edge[0]);
        }
      };
      fill_adj(edges1, adj1);
      fill_adj(edges2, adj2);
    }
    auto procedure = [this](unordered_map<int, vector<int>> &adj) -> int {
      int d = 0;
      unordered_map<int, bool> visit;
      if (!adj.empty()) {
        auto p = get_diameter(adj.begin()->first, adj, visit);
        visit.clear();
        d = get_diameter(p.second, adj, visit).first;
      }
      return d;
    };
    int d1 = procedure(adj1);
    int d2 = procedure(adj2);
    return max({d1, d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1});
  }

private:
  pair<int, int> get_diameter(int val, unordered_map<int, vector<int>> &adj,
                              unordered_map<int, bool> &v) {
    v[val] = true;
    pair<int, int> d{0, val};
    for (const auto &node : adj[val]) {
      if (v[node])
        continue;
      auto temp_d = get_diameter(node, adj, v);
      if (temp_d.first + 1 > d.first) {
        d.first = temp_d.first + 1;
        d.second = temp_d.second;
      }
    }
    return d;
  }
};
