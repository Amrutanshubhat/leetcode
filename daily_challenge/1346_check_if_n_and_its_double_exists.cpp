class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    const int offset = 1000;
    const int arr_size = 2 * offset + 1;
    unsigned char ht[arr_size] = {0};

    for (const auto &num : arr) {
      if (!(abs(num) & 1) && ht[num / 2 + offset])
        return true;
      int val = num * 2 + offset;
      if (val >= 0 && val < arr_size && ht[val])
        return true;
      ht[num + offset] = 1;
    }
    return false;
  }
};
