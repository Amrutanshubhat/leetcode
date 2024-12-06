class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    const int max_len = (1e4) + 1;
    unsigned char ht[max_len] = {0};
    for (const auto &i : banned) {
      ht[i] = 1;
    }
    int x = min(n, (int)((sqrt(1 + (8 * (long)maxSum)) - 1) / 2));
    int diff = maxSum - (x * (x + 1) * 0.5);
    int removed = 0;
    for (size_t i = 0; i < max_len; i++) {
      if (ht[i] == 0)
        continue;
      if (i > x)
        break;
      diff += i;
      removed++;
      while (diff >= x + 1 && x < n) {
        diff -= ++x;
      }
    }
    return x - removed;
  }
};
