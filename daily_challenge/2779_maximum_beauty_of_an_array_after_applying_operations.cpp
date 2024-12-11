class Solution {
public:
  int maximumBeauty(vector<int> &nums, int k) {
    size_t n = nums.size();
    vector<pair<int, int>> arr(n);
    for (size_t i = 0; i < n; i++) {
      arr[i].first = nums[i] - k;
      arr[i].second = nums[i] + k;
    }
    sort(arr.begin(), arr.end());
    int out = 0;
    auto cmp = [](const int val, pair<int, int> p) -> bool {
      return val < p.first;
    };
    for (size_t i = 0; i < n; i++) {
      int sub = upper_bound(arr.begin(), arr.end(), arr[i].second, cmp) -
                arr.begin() - i;
      if (out < sub)
        out = sub;
    }
    return out;
  }
};
