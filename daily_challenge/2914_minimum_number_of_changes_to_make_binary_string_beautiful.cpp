class Solution {
public:
  int minChanges(string s) {
    int cnt = 0;
    for (size_t i = 0, n = s.size() - 1; i < n; i += 2) {
      if (s[i] != s[i + 1])
        cnt++;
    }
    return cnt;
  }
};
