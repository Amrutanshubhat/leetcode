class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    size_t n = arr.size();
    int out = 1;
    for (size_t i = 0; i < (1 << n); i++) {
      int prev = 0, cur = arr[0], cnt = 1;
      for (size_t j = 1; j < arr.size(); j++) {
        if (((i >> j) ^ (i >> (j - 1))) & 1) {
          prev = cur;
          cur = arr[j];
          cnt++;
        } else {
          cur = max(cur, arr[j]);
        }
        if (arr[j] < prev) {
          cnt = 1;
          break;
        }
      }
      out = max(out, cnt);
    }
    return out;
  }
};
