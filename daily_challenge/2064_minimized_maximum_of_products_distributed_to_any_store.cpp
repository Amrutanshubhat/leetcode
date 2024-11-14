class Solution {
public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1, r = 1;
    for (const auto &q : quantities)
      if (q > r)
        r = q;
    while (l <= r) {
      int mid = (l + r + 1) / 2;
      if (canfit(quantities, n, mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }

private:
  bool canfit(vector<int> &arr, int n, int x) {
    size_t store = 0;
    for (size_t i = 0; i < arr.size() && store <= n; i++) {
      store += (arr[i] + x - 1) / x;
    }
    if (store > n)
      return false;
    return true;
  }
};
