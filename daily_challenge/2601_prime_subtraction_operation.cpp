class Solution {
#define MAXVAL 1001
  typedef unsigned char u8;
  u8 prime[MAXVAL];

public:
  bool primeSubOperation(vector<int> &nums) {
    size_t n = nums.size();
    memset(prime, 1, sizeof(prime));

    // fill prime
    {
      prime[1] = false;
      size_t x = 2;
      size_t p = pow(x, 2);
      while (p < MAXVAL) {
        if (prime[x]) {
          for (size_t i = p; i < MAXVAL; i += x) {
            prime[i] = false;
          }
        }
        x++;
        p = pow(x, 2);
      }
    }
    nums[0] -= get_prime(nums[0]);
    for (size_t i = 1; i < n; i++) {
      if (nums[i] <= nums[i - 1])
        return false;
      int x = get_prime(nums[i]);
      while (nums[i - 1] >= nums[i] - x) {
        x = get_prime(x);
      }
      nums[i] -= x;
    }
    print_array(nums);
    return true;
  }

private:
  int get_prime(int x) {
    for (int i = x - 1; i > 0; i--) {
      if (prime[i])
        return i;
    }
    return 0;
  }
};
