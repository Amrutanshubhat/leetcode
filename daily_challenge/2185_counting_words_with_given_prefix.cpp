class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int cnt = 0;
    for (const auto &word : words) {
      if (pref.size() > word.size())
        continue;
      size_t i = 0;
      while (i < pref.size()) {
        if (pref[i] != word[i])
          break;
        i++;
      }
      if (i == pref.size())
        cnt++;
    }
    return cnt;
  }
};
