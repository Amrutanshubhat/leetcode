class Solution {
  unordered_map<int, int> ht, wht;

public:
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    vector<int> out(queries.size());
    dfs(root, 0, 0);
    for (size_t i = 0; i < queries.size(); i++) {
      out[i] = wht[queries[i]];
    }
    return out;
  }

private:
  int height(TreeNode *root) {
    if (!root)
      return 0;

    if (ht.find(root->val) != ht.end())
      return ht[root->val];

    return ht[root->val] = 1 + max(height(root->left), height(root->right));
  }
  void dfs(TreeNode *root, int d, int h) {
    if (!root)
      return;
    wht[root->val] = h;
    dfs(root->left, d + 1, max(h, d + height(root->right)));
    dfs(root->right, d + 1, max(h, d + height(root->left)));
  }
};
