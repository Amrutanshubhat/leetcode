class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
    sort(items.begin(), items.end(),
         [](vector<int> &x, vector<int> &y) -> bool { return x[0] < y[0]; });

    // each items should contain maxbeauty until it's price
    for (size_t i = 0, max_beauty = 0; i < items.size(); i++) {
      if (items[i][1] > max_beauty)
        max_beauty = items[i][1];
      else if (max_beauty > items[i][1])
        items[i][1] = max_beauty;
    }

    vector<int> out;
    for (const auto &query : queries) {
      size_t index =
          upper_bound(items.begin(), items.end(), query,
                      [](const int val, const vector<int> &x) -> bool {
                        return val < x[0];
                      }) -
          items.begin();
      if (index == 0)
        out.push_back(0);
      else
        out.push_back(items[index - 1][1]);
    }
    return out;
  }
};
