class Solution {
public:
  vector<int> resultsArray(vector<int> &nums, int k) {
    size_t n = nums.size();
    vector<int> out(n - k + 1, -1);
    for (size_t p = 0, q = p + 1; p < out.size();) {
      while (q < p + k && nums[q] == nums[q - 1] + 1)
        q++;
      if (q == p + k) {
        out[p] = nums[q - 1];
        p++;
      } else {
        p = q++;
      }
    }
    return out;
  }
};
