class Solution {
public:
  int possibleStringCount(string word) {
    size_t out = 1;
    for (size_t i = 1; i < word.size(); i++) {
      if (word[i] == word[i - 1])
        out++;
    }
    return out;
  }
};
