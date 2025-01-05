class Solution {
public:
  bool hasMatch(string s, string p) {
    string first, last;
    for (size_t i = 0, x = 0; i < p.size(); i++) {
      if (p[i] == '*') {
        x++;
        continue;
      }
      if (x == 0)
        first.push_back(p[i]);
      else
        last.push_back(p[i]);
    }

    if (first.empty()) {
      if (last.empty())
        return true;
      if (s.find(last) == s.npos)
        return false;
      return true;
    }
    int a = s.find(first);
    if (a == s.npos)
      return false;
    if (last.empty())
      return true;
    if (s.find(last, a + first.size()) == s.npos)
      return false;
    return true;
  }
};
