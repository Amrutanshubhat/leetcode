class Solution {
public:
  vector<int> largestValues(TreeNode *root) {
    vector<int> out;
    if (!root)
      return out;
    queue<TreeNode *> q{{root}};
    q.emplace(nullptr);
    int maxval = INT_MIN;
    while (!q.empty()) {
      auto temp = q.front();
      q.pop();
      if (temp == nullptr) {
        if (!q.empty())
          q.emplace(nullptr);
        out.push_back(maxval);
        maxval = INT_MIN;
      } else {
        if (temp->val > maxval)
          maxval = temp->val;
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
    }
    return out;
  }
};
