class Solution {
public:
  string compressedString(string word) {
    string comp;
    uint8_t cnt = 1;

    for (size_t i = 1; i < word.size(); i++) {

      if (word[i] != word[i - 1] or cnt == 9) {
        comp.push_back(cnt + '0');
        comp.push_back(word[i - 1]);
        cnt = 0;
      }

      cnt++;
    }
    comp.push_back(cnt + '0');
    comp.push_back(word.back());
    return comp;
  }
};
