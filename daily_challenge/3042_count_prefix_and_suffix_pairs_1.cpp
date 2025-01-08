class Solution {
public:
  int countPrefixSuffixPairs(vector<string> &words) {
    auto IsPrefSuf = [](const string &a, const string &b) -> bool {
      if (b.size() < a.size())
        return false;
      for (int i = 0; i < a.size(); i++) {
        if ((a[i] != b[i]) || (a[a.size() - i - 1] != b[b.size() - i - 1]))
          return false;
      }
      return true;
    };
    int cnt = 0;
    for (size_t i = 0; i < words.size(); i++) {
      for (size_t j = i + 1; j < words.size(); j++) {
        if (IsPrefSuf(words[i], words[j]))
          cnt++;
      }
    }
    return cnt;
  }
};
