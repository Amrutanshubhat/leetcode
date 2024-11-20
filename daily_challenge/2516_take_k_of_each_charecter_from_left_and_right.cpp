class Solution {
public:
  int takeCharacters(string s, int k) {
    size_t n = s.size();
    vector<vector<int>> ps(n + 1, vector<int>(3));
    for (size_t i = 1; i <= n; i++) {
      ps[i] = ps[i - 1];
      ps[i][s[i - 1] - 'a']++;
    }

    if (ps[n][0] < k || ps[n][1] < k || ps[n][2] < k)
      return -1;

    int out = n;
    for (size_t i = 0, j = 0; j <= n && i <= j; i++) {

      while (j <= n && (ps[n][0] - ps[j][0] >= k - ps[i][0]) &&
             (ps[n][1] - ps[j][1] >= k - ps[i][1]) &&
             (ps[n][2] - ps[j][2] >= k - ps[i][2])) {

        out = min(out, (int)(n - j + i));
        j++;
      }
    }
    return out;
  }
};
