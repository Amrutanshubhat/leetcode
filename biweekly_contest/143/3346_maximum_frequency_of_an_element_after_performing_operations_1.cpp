class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> ht;
    unordered_set<int> st;

    for (const auto &num : nums) {
      st.insert(num);
      st.insert(num + k);
      st.insert(num - k);

      ht[num]++;
    }
    int out = 1;
    for (const auto &num : st) {
      auto iter_num_ub = upper_bound(nums.begin(), nums.end(), num);
      auto iter_num_lb = lower_bound(nums.begin(), nums.end(), num);
      auto iter_ub = upper_bound(nums.begin(), nums.end(), num + k);
      auto iter_lb = lower_bound(nums.begin(), nums.end(), num - k);

      int tot_op = (iter_ub - iter_num_ub) + (iter_num_lb - iter_lb);
      int swap = min(numOperations, tot_op);
      out = max(out, ht[num] + swap);
    }
    return out;
  }
};
