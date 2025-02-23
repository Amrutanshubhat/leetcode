class Solution {
	int idx;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
	{
		idx = 0;
		return dfs(preorder, postorder, 0, postorder.size());
    }

private:
	inline int get_index(vector<int>& arr, int start, int end, int val)
	{
		auto pos = find(arr.begin()+start, arr.begin()+end, val);
		return pos-arr.begin();
	}

	TreeNode* dfs(vector<int>& pre, vector<int>& post, int start, int end)
	{
		if (idx == pre.size()) return nullptr;

		TreeNode *root = new TreeNode(pre[idx++]);
		if (idx == pre.size()) return root;

		int x = get_index(post, start, end, pre[idx]);
		if (x == end) return root;

		root->left = dfs(pre, post, start, x);

		if (idx == pre.size()) return root;

		int y = get_index(post, x+1, end, pre[idx]);
		if (y == end) return root;

		root->right = dfs(pre, post, x+1, end);

		return root;
	}
};
