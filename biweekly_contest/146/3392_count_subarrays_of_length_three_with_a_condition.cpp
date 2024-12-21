class Solution {
public:
  int countSubarrays(vector<int> &nums) {
    int cnt = 0;
    for (int i = 2; i < nums.size(); i++) {
      if (((nums[i] + nums[i - 2]) * 2) == nums[i - 1])
        cnt++;
    }
    return cnt;
  }
};
