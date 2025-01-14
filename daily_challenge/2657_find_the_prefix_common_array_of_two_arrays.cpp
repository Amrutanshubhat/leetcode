class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    const int n = A.size();
    int ht[n + 1];
    memset(ht, 0, sizeof(*ht) * (n + 1));
    vector<int> out(n);
    for (int i = 0, cnt = 0; i < n; i++) {
      ht[A[i]]++;
      ht[B[i]]++;
      if (ht[A[i]] == 2)
        cnt++;
      if (B[i] != A[i] && ht[B[i]] == 2)
        cnt++;
      out[i] = cnt;
    }
    return out;
  }
};
