class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    const int m = mat.size(), n = mat[0].size(), mat_size = arr.size();
    vector<int> row(m), col(n);
    vector<pair<int, int>> ht(mat_size + 1);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        ht[mat[i][j]] = {i, j};

    for (int i = 0; i < mat_size; i++) {
      int r = ht[arr[i]].first, c = ht[arr[i]].second;
      row[r]++;
      col[c]++;
      if (row[r] == n || col[c] == m)
        return i;
    }
    return mat_size - 1;
  }
};
