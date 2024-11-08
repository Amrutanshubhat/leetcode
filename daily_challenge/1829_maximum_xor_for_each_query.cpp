class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    size_t n = nums.size();
    size_t limit = (1 << maximumBit) - 1;
    vector<int> out(n);
    int ex = 0;
    for (size_t i = 0; i < n; i++) {
      ex ^= nums[i];
      out[n - i - 1] = ~ex & limit;
    }
    return out;
  }
};
