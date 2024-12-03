class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    string out;
    out.resize((s.size() + spaces.size()), ' ');

    for (size_t i = 0, j = 0, x = 0; i < s.size(); i++) {
      if (j < spaces.size() && i == spaces[j]) {
        x++;
        j++;
      }
      out[x++] = s[i];
    }
    return out;
  }
};
