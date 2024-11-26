class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    unsigned ht[n];
    memset(ht, 0, sizeof(ht));

    for (const auto &edge : edges) {
      ht[edge[1]] = 1;
    }

    int stronger = -1;
    for (size_t i = 0; i < n; i++) {
      if (!ht[i]) {
        if (stronger != -1)
          return -1;
        stronger = i;
      }
    }
    return stronger;
  }
};
