class Solution {
#define ALPHABET_SIZE 26
public:
  vector<int> findSubtreeSizes(vector<int> &parent, string s) {
    size_t n = parent.size();
    vector<int> new_parent(n);
    vector<int> out(n, 1);

    for (int i = n - 1; i >= 0; i--) {
      int x = parent[i];

      while (x != -1 && s[x] != s[i])
        x = parent[x];

      if (x != -1)
        new_parent[i] = x;
      else
        new_parent[i] = parent[i];
    }
    for (size_t i = 0; i < n; i++) {
      int x = new_parent[i];
      while (x != -1) {
        out[x]++;
        x = new_parent[x];
      }
    }
    return out;
  }
};
