class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int out = INT_MAX;
    size_t n = nums.size();
    vector<long> ps(n + 1);
    for (size_t i = 1; i <= n; i++) {
      ps[i] = ps[i - 1] + nums[i - 1];
    }
    deque<int> q;
    for (int i = 0; i <= n; i++) {
      while (!q.empty() && ps[i] - ps[q.front()] >= k) {
        out = min(out, i - q.front());
        q.pop_front();
      }
      // store -ve num in asc order which yieds min subarray
      while (!q.empty() && ps[i] <= ps[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }
    return out == INT_MAX ? -1 : out;
  }
};
