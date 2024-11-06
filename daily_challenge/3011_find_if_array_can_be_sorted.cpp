class Solution {
public:
  bool canSortArray(vector<int> &nums) {
    int ht[nums.size()];
    for (size_t i = 0; i < nums.size(); i++) {
      size_t cnt = 0;
      int num = nums[i];
      while (num) {
        if (num & 1)
          cnt++;
        num >>= 1;
      }
      ht[i] = cnt;
    }
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        if ((nums[i] > nums[j]) && (ht[i] != ht[j]))
          return false;
      }
    }
    return true;
  }
};
