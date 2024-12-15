class Solution {
public:
  long long continuousSubarrays(vector<int> &nums) {
    size_t i = 0, j = 0, k = 0, m = 0, out = 0;
    while (true) {
      while (j < nums.size() && abs(nums[j] - nums[k]) < 3 &&
             abs(nums[j] - nums[m]) < 3) {
        if (nums[j] >= nums[k])
          k = j;
        if (nums[j] <= nums[m])
          m = j;
        j++;
      }
      if (j == nums.size()) {
        out += (j - i + 1) * (j - i) * 0.5;
        break;
      }
      int min_shift;
      if (abs(nums[k] - nums[j]) > 2)
        min_shift = k;
      else
        min_shift = m;
      while (i <= min_shift) {
        out += j - i;
        i++;
      }
      k = i;
      m = i;
      j = i;
    }
    return out;
  }
};
