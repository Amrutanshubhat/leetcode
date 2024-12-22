class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int> &heights,
                                      vector<vector<int>> &queries) {
    int cnt = 0;
    vector<int> out(queries.size(), -1);
    for (auto &query : queries) {
      if (query[0] > query[1]) {
        int temp = query[1];
        query[1] = query[0];
        query[0] = temp;
      }
      query.push_back(cnt++);
    }
    sort(queries.begin(), queries.end(),
         [](const vector<int> &x, const vector<int> &y) -> bool {
           return x[1] > y[1];
         });

    auto cmp = [&heights](int x, int y) -> bool {
      return heights[x] < heights[y];
    };

    size_t n = heights.size() - 1;
    vector<int> ms;
    for (const auto &query : queries) {
      int a = query[0], b = query[1], idx = query[2];
      if (a == b || heights[a] < heights[b]) {
        out[idx] = b;
      } else {
        while (n > b) {
          while (!ms.empty() && heights[ms.back()] <= heights[n])
            ms.pop_back();
          ms.push_back(n--);
        }
        auto it = upper_bound(ms.rbegin(), ms.rend(), a, cmp);
        if (it != ms.rend())
          out[idx] = *it;
      }
    }
    return out;
  }
};
