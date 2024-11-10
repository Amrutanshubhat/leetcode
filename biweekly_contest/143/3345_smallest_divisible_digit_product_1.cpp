class Solution {
public:
  int smallestNumber(int n, int t) {
    int x = n;
    while (!isdivisible(x, t))
      x++;
    return x;
  }

private:
  bool isdivisible(int x, int t) {
    size_t p = 1;
    while (x) {
      p *= x % 10;
      x /= 10;
    }
    if (p % t)
      return false;
    return true;
  }
};
