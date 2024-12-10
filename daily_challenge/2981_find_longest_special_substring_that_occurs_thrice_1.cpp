class Solution {
public:
  int maximumLength(string s) {
    int len = 1;
    int out = substring_cnt(s, 0, len);
    for (size_t i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1])
        len++;
      else
        len = 1;
      out = max(out, substring_cnt(s, i + 1 - len, len));
    }
    return out > 0 ? out : -1;
  }

private:
  int substring_cnt(const string &s, const int index, const int len) {
    int cnt = 0;
    for (size_t i = index; i < (s.size() - len + 1); i++) {
      size_t x = 0;
      while (x < len && s[i + x] == s[index])
        x++;
      if (x == len)
        cnt++;
    }
    return cnt > 2 ? len : 0;
  }
};
