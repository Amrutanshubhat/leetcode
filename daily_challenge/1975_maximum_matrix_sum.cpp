class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    size_t m = matrix.size(), n = matrix[0].size();
    int small = INT_MAX, neg = 0;
    long long cnt = 0;
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (abs(matrix[i][j]) < small)
          small = abs(matrix[i][j]);
        if (matrix[i][j] < 0)
          neg++;
        cnt += abs(matrix[i][j]);
      }
    }
    return neg & 1 ? cnt - 2 * small : cnt;
  }
};
