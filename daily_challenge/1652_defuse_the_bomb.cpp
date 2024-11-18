class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    size_t n = code.size();
    vector<int> out(n);
    if (k > 0) {
      int tot = 0;
      for (int i = 0; i < k; i++) {
        tot += code[(1 + i) % n];
      }
      out[0] = tot;
      for (int i = 1; i < n; i++) {
        out[i] = out[i - 1] - code[i] + code[(i + k) % n];
      }
    } else if (k < 0) {
      int tot = 0;
      for (int i = k; i != 0; i++) {
        tot += code[(n + i) % n];
      }
      out[0] = tot;
      for (int i = 1; i < n; i++) {
        out[i] = code[i - 1] + out[i - 1] - code[(n + i + k - 1) % n];
      }
    }
    return out;
  }
};
