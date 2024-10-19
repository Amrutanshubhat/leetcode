class Solution {
public:
  char findKthBit(int n, int k) {
    if (n == 1)
      return '0';
    size_t len = (1 << n) - 1;
    size_t mid = 1 + len / 2;
    if (k == mid)
      return '1';
	if (k < mid)
      return findKthBit(n - 1, k);
    // bits are inversed and reversed, so undo it for prev iteration
    return findKthBit(n - 1, len - k + 1) == '1' ? '0' : '1';
  }
};
