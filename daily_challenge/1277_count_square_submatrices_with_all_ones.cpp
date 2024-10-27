class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int cnt = 0;
    size_t m = matrix.size(), n = matrix[0].size();
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (!matrix[i][j])
          continue;
        // right down | left up
        size_t k, x = 0;
        for (k = 0; i + k < m and j + k < n and x == 0 and 
				matrix[i][j + k] and matrix[i + k][j]; k++) {

			for (x = k; x > 0 and 
					matrix[i + x][j + k] and matrix[i + k][j + x]; x--);

			if (x == 0)
				cnt++;
        }
      }
    }
    return cnt;
  }
};
