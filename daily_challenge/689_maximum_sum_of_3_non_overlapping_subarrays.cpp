class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    size_t n = nums.size();
    vector<int> arr(n + 1);
    for (size_t i = 0; i < k; i++) {
      arr[1] += nums[i];
    }
    for (size_t i = 1; i <= n - k; i++) {
      arr[i + 1] = arr[i] - nums[i - 1] + nums[i + k - 1];
    }

    vector<int> arr1(n + 1);
    int idx = 0;
    for (size_t i = 1; i <= n - k + 1; i++) {
      if (arr[i] > arr[idx]) {
        idx = i;
      }
      arr1[i] = idx;
    }

    vector<int> arr2(n + 1);
    idx = n;
    for (size_t i = n - k + 1; i > 0; i--) {
      if (arr[idx] <= arr[i]) {
        idx = i;
      }
      arr2[i] = idx;
    }

    size_t maxtot = 0;
    vector<int> out;
    for (int i = k + 1; i <= n - k; i++) {
      int x = arr1[i - k], y = arr2[i + k];
      size_t tot = arr[x] + arr[i] + arr[y];
      if (tot > maxtot) {
        maxtot = tot;
        out = vector<int>{x - 1, i - 1, y - 1};
      }
    }
    return out;
  }
};
