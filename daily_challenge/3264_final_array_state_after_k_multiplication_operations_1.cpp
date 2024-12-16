class Solution {
public:
  // priority_queue can be used however input size is very small.
  // better off with O(kn) operations
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    while (k--) {
      int x = 0;
      for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[x])
          x = i;
      }
      nums[x] *= multiplier;
    }
    return nums;
  }
};
