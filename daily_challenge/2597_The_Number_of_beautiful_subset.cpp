class Solution {
public:
  int beautifulSubsets(vector<int> &nums, int k) {
    int out = 0;
    bool ht[1001] = {0};
    for (int i = 0; i < (1 << nums.size()); i++) {
      vector<int> s;
      for (int j = 0; j < nums.size(); j++) {
        if ((1 & (i >> j))) {
          if ((nums[j] - k >= 0 && ht[nums[j] - k]) ||
              (nums[j] + k < 1001 && ht[nums[j] + k])) {
            out--;
            break;
          } else
            ht[nums[j]] = true;
        }
      }
      memset(ht, 0, sizeof(ht));
      out++;
    }
    return out - 1;
  }
};
