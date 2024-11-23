class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    size_t m = box.size(), n = box[0].size();

    for (size_t r = 0; r < m; r++) {
      int p = n - 1;
      for (int i = n - 1; i >= 0; i--) {
        while (i >= 0 && box[r][i] != '#') {
          if (box[r][i] == '*')
            p = i - 1;
          i--;
        }
        if (i >= 0) {
          box[r][i] = '.';
          box[r][p--] = '#';
        }
      }
    }
    vector<vector<char>> out(n, vector<char>(m));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        out[j][m - i - 1] = box[i][j];
      }
    }
    return out;
  }
};
