class Solution {
	vector<int> v;
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);
		int tot = 0;
		while (!q.empty()) {
			TreeNode* temp = q.front(); q.pop();
			if (temp == nullptr) {
				if (!q.empty()) {
					q.push(temp);
				}
				v.push_back(tot);
				tot = 0;
			} else {
				tot += temp->val;
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
		}
		dfs(root, 0, root->val);
		return root;
    }
private:
	void dfs(TreeNode* root, int depth, int tot) {
		if (root == nullptr) return;
		root->val = v[depth]-tot;
		int children_tot = 0;
		if (root->left) {
			children_tot += root->left->val;
		}
		if (root->right) {
			children_tot += root->right->val;
		}
		dfs(root->left, depth+1, children_tot);
		dfs(root->right, depth+1, children_tot);
	}
};
