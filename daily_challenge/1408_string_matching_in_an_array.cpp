class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> out;
    for (size_t i = 0; i < words.size(); i++) {
      for (size_t j = 0; j < words.size(); j++) {
        if (i == j)
          continue;
        if (words[j].find(words[i]) != words[j].npos) {
          out.push_back(words[i]);
          break;
        }
      }
    }
    return out;
  }
};
