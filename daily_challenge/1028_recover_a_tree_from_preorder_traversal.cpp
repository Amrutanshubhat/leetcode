class Solution {
	vector<pair<int, int>> arr;
	int index;
public:
    TreeNode* recoverFromPreorder(string traversal) {
		const int n = traversal.size();	
		for (int i=0, level=0; i<n;) {
			string temp;
			while (i<n && isdigit(traversal[i])) {
				temp += traversal[i];
				i++;
			}
			if (!temp.empty()) {
				int val = stoi(temp);
				arr.emplace_back(make_pair(val, level));
				level = 0;
				while (traversal[i] == '-') {
					i++; level++;
				}
			}
		}
		TreeNode *root = new TreeNode(arr.front().first);
		index = 1;
		dfs(root, 1);
		return root;
    }
private:
	void dfs(TreeNode *root, int level) {
		if (index == arr.size() || arr[index].second != level) return;
		if (!root->left) {
			root->left = new TreeNode(arr[index].first);
			index++;
			dfs(root->left, level+1);
		}
		if (index < arr.size() && arr[index].second == level) {
			root->right = new TreeNode(arr[index].first);
			index++;
			dfs(root->right, level+1);
		}
	}
};
