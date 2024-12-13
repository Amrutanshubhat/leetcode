class Solution {
  struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
      if (a.first == b.first)
        return a.second > b.second;
      return a.first > b.first;
    }
  };

public:
  long long findScore(vector<int> &nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    for (size_t i = 0; i < nums.size(); i++) {
      q.emplace(make_pair(nums[i], i + 1));
    }
    vector<bool> ht(nums.size() + 1);
    size_t sum = 0;
    while (!q.empty()) {
      int index = q.top().second;
      int val = q.top().first;
      q.pop();
      if (!ht[index]) {
        ht[index + 1] = ht[index] = ht[index - 1] = true;
        sum += val;
      }
    }
    return sum;
  }
};
