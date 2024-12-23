class Solution {
public:
  int minimumOperations(TreeNode *root) {
    int cnt = 0;
    queue<TreeNode *> q{{root}};
    q.push(nullptr);

    map<int, int> m;
    vector<int> v;
    auto selection_sort = [&cnt, &m, &v]() -> void {
      int x = 0;
      for (auto &[val, idx] : m) {
        if (v[x] != val) {
          v[idx] = v[x];
          m[v[idx]] = idx;
          cnt++;
        }
        x++;
      }
    };
    int idx = 0;
    while (!q.empty()) {
      auto temp = q.front();
      q.pop();
      if (temp == nullptr) {
        if (!q.empty())
          q.push(temp);
        selection_sort();
        m.clear();
        v.clear();
        idx = 0;
      } else {
        m[temp->val] = idx++;
        v.push_back(temp->val);
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
    }
    return cnt;
  }
};
