class Solution {
public:
  long long kthLargestLevelSum(TreeNode *root, int k) {
    vector<size_t> arr;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);
    size_t tot = 0;
    while (!q.empty()) {
      TreeNode *temp = q.front();
      q.pop();
      if (temp == nullptr) {
        if (!q.empty())
          q.push(temp);
        arr.push_back(tot);
        tot = 0;
      } else {
        tot += temp->val;
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
    }
	if (arr.size() < k) return -1;
    sort(arr.begin(), arr.end(), greater<size_t>());
    return arr[k - 1];
  }
};
