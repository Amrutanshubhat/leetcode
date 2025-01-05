class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {
    size_t n = s.size();
    vector<int> ht(n + 1);
    constexpr int ALPHA = 26;
    for (const auto &shift : shifts) {
      int dir = 1;
      if (shift[2] == 0)
        dir = -1;
      ht[shift[0] + 1] += dir;
      ht[shift[1] + 1] += (-dir);
    }

    for (size_t i = 0; i < n; i++) {
      auto iter = &ht[i + 1];
      *iter += ht[i];
      int x = abs((*iter)) % ALPHA;
      if (x == 0)
        continue;
      if ((*iter) < 0) {
        int temp = s[i] - x;
        if (temp < 'a') {
          temp = 'a' - temp - 1;
          s[i] = 'z' - temp;
        } else
          s[i] = (char)temp;
      } else {
        int temp = s[i] + x;
        if (temp > 'z') {
          temp = temp - 'z' - 1;
          s[i] = 'a' + temp;
        } else
          s[i] = (char)temp;
      }
    }
    return s;
  }
};
