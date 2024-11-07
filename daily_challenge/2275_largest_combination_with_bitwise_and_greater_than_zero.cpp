class Solution {
#define BIT_CNT 31
public:
  int largestCombination(vector<int> &candidates) {
    int ht[BIT_CNT];
    memset(ht, 0, sizeof(ht));
    int max_cnt = 1;
    for (int candidate : candidates) {
      int shift_cnt = 0;
      while (candidate) {
        ht[shift_cnt++] += candidate & 1;
        candidate >>= 1;
      }
    }
    for (size_t i = 0; i < BIT_CNT; i++) {
      if (ht[i] > max_cnt)
        max_cnt = ht[i];
    }
    return max_cnt;
  }
};
