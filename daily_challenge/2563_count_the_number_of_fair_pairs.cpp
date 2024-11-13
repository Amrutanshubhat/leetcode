class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    // total pairs less than or equal to upper - total pairs less than lower
    return get_cnt(nums, upper) - get_cnt(nums, lower - 1);
  }

private:
  size_t get_cnt(vector<int> &nums, int max_val) {
    size_t cnt = 0;
    size_t l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] + nums[r] > max_val)
        r--;
      else
        cnt += r - l++;
    }
    return cnt;
  }
};
