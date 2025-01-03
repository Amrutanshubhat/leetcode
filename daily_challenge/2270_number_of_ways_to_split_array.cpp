class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    size_t n = nums.size();
    long long *ps = (long long *)alloca(sizeof(*ps) * (n + 1));
    ps[0] = 0;
    for (size_t i = 0; i < n; i++) {
      ps[i + 1] = ps[i] + nums[i];
    }

    int count = 0;
    for (size_t i = 1; i < n; i++) {
      if (ps[i] >= ps[n] - ps[i])
        count++;
    }
    return count;
  }
};
