class Solution {
public:
  long long shiftDistance(string s, string t, vector<int> &nextCost,
                          vector<int> &previousCost) {
    const int alphabet_sz = 26;
    vector<long long> fs(alphabet_sz), bs(alphabet_sz);
    fs[0] = nextCost[0], bs[alphabet_sz - 1] = previousCost[alphabet_sz - 1];

    for (int i = 1, j = alphabet_sz - 2; i < alphabet_sz; i++, j--) {
      fs[i] = fs[i - 1] + nextCost[i];
      bs[j] = bs[j + 1] + previousCost[j];
    }

    long long out = 0;
    for (size_t i = 0; i < s.size(); i++) {
      int x = s[i] - 'a', y = t[i] - 'a';
      if (x == y)
        continue;
      long long pd, nd;
      if (x < y) {
        pd = bs[0] - bs[x] + previousCost[x] + bs[y] - previousCost[y];
        nd = fs[y] - nextCost[y] - fs[x] + nextCost[x];
      } else {
        pd = bs[y] - previousCost[y] - bs[x] + previousCost[x];
        nd = fs[alphabet_sz - 1] - fs[x] + nextCost[x] + fs[y] - nextCost[y];
      }
      out += min(pd, nd);
    }
    return out;
  }
};
