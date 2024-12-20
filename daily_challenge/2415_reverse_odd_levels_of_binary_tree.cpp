class Solution {
public:
  TreeNode *reverseOddLevels(TreeNode *root) {
    vector<vector<TreeNode *>> v;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    int level = 0;
    while (!q.empty()) {
      TreeNode *temp = q.front();
      q.pop();
      if (temp == nullptr) {
        level++;
        if (!q.empty()) {
          q.push(temp);
          if (level & 1)
            v.emplace_back(vector<TreeNode *>{});
        }
      } else {
        if (level & 1) {
          v[level / 2].push_back(temp);
        }
        if (temp->left)
          q.emplace(temp->left);
        if (temp->right)
          q.emplace(temp->right);
      }
    }
    for (auto &arr : v) {
      for (int i = 0, j = arr.size() - 1; i < j; i++, j--) {
        int temp = arr[j]->val;
        arr[j]->val = arr[i]->val;
        arr[i]->val = temp;
      }
    }
    return root;
  }
};
