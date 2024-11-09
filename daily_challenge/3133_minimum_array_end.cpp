class Solution {
public:
  long long minEnd(int n, int x) {
    size_t out = 0;
    n--;
    for (size_t i = 0; (n > 0) || (x > 0); x >>= 1, i++) {
      if (x & 1) {
        out += 1 << i;
      } else {
        out += (n & 1) << i;
        n >>= 1;
      }
    }
    return out;
  }
};
