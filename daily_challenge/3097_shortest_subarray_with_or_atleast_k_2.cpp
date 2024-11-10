class Solution {
#define BIT_CNT 31
public:
  int minimumSubarrayLength(vector<int> &nums, int k) {
    if (k == 0)
      return 1;
    int ht[BIT_CNT] = {0};
    int cnt = INT_MAX;

    for (int p = 0, q = 0; p < nums.size();) {
      while (q < nums.size() && get_val(ht) < k) {
        inc(ht, nums[q++]);
      }
      if (get_val(ht) < k)
        break;
      while (p < q && get_val(ht) >= k) {
        dec(ht, nums[p++]);
      }
      cnt = min(cnt, q - p + 1);
    }
    return cnt == INT_MAX ? -1 : cnt;
  }

private:
  void dec(int *ht, int num) {
    int x = 0;
    while (num) {
      ht[x++] -= num & 1;
      num >>= 1;
    }
  }
  void inc(int *ht, int num) {
    int x = 0;
    while (num) {
      ht[x++] += num & 1;
      num >>= 1;
    }
  }
  int get_val(int *ht) {
    int out = 0;
    for (int i = 0; i < BIT_CNT; i++) {
      if (ht[i] > 0)
        out += 1 << i;
    }
    return out;
  }
};
