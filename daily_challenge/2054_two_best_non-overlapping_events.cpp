class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    auto cmp = [](const vector<int> &a, const vector<int> &b) -> bool {
      if (a[0] == b[0])
        return a[1] < b[1];
      return a[0] < b[0];
    };
    sort(events.begin(), events.end(), cmp);
    const size_t n = events.size();

    vector<int> ht(n + 1), st(n);
    for (ssize_t j = n - 1; j >= 0; j--) {
      ht[j] = max(ht[j + 1], events[j][2]);
      st[j] = events[j][0];
    }

    int max_val = 0;
    for (const auto &event : events) {
      int index = upper_bound(st.begin(), st.end(), event[1]) - st.begin();
      max_val = max(max_val, ht[index] + event[2]);
    }
    return max_val;
  }
};
