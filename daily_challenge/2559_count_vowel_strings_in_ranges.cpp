class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    size_t n = words.size();
    int ps[n + 1];
    memset(ps, 0, sizeof(ps));
    const string vowels = "aeiou";
    for (size_t i = 0; i < n; i++) {
      if ((vowels.find_first_of(words[i].front()) != vowels.npos) &&
          (vowels.find_first_of(words[i].back()) != vowels.npos))
        ps[i + 1] = ps[i] + 1;
      else
        ps[i + 1] = ps[i];
    }
    vector<int> out;
    for (const auto &q : queries)
      out.emplace_back(ps[q[1] + 1] - ps[q[0]]);
    return out;
  }
};
