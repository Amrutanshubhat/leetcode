class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    size_t m = matrix.size(), n = matrix[0].size();
    vector<int> ht(m, 1);
    int out = 1;
    for (size_t i = 0; i < m; i++) {
      for (size_t j = i + 1; j < m; j++) {
        uint8_t x = matrix[i][0] ^ matrix[j][0];
        size_t c = 1;
        for (; c < n && ((matrix[i][c] ^ matrix[j][c]) == x); c++)
          ;
        if (c == n)
          ht[i]++;
      }
      out = max(out, ht[i]);
    }
    return out;
  }
};
