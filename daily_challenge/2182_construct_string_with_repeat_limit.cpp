class Solution {
#define ALPHA 26
public:
  string repeatLimitedString(string s, int repeatLimit) {
    int cnt[ALPHA] = {0};
    for (size_t i = 0; i < s.size(); i++)
      cnt[s[i] - 'a']++;
    auto get_next_index = [&cnt](int x) -> int {
      for (; x >= 0 && cnt[x] == 0; x--)
        ;
      return x;
    };
    int i = get_next_index(ALPHA - 1);
    string out{(char)(i + 'a')};
    cnt[i]--;
    i = get_next_index(i);
    for (int rep = 1, j; i >= 0; i = get_next_index(i)) {
      if ((char)out.back() == ('a' + i)) {
        if (rep == repeatLimit) {
          j = get_next_index(i - 1);
          if (j < 0)
            return out;
          out.push_back((char)(j + 'a'));
          cnt[j]--;
          rep = 1;
        } else {
          out.push_back((char)('a' + i));
          cnt[i]--;
          rep++;
        }
      } else {
        out.push_back((char)('a' + i));
        cnt[i]--;
        rep = 1;
      }
    }
    return out;
  }
};
