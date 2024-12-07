class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    while (l <= r) {
      int p = (l + r) / 2;
      if (total_op(nums, p) > maxOperations)
        l = p + 1;
      else
        r = p - 1;
    }
    return l;
  }

private:
  int total_op(vector<int> &nums, int p) {
    int tot = 0;
    for (const auto &num : nums)
      tot += (num - 1) / p;
    return tot;
  }
};
