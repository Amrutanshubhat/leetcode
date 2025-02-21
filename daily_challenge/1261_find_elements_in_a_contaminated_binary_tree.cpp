class FindElements {
	unordered_set<int> node_val;
public:
    FindElements(TreeNode* root) {
		root->val = 0;
 		queue<TreeNode *> q{{root}};

		while (!q.empty()) {
			const int n = q.size();
			for (int i=0; i<n; i++) {
				auto temp = q.front(); q.pop();
				node_val.insert(temp->val);
				if (temp->left) {
					temp->left->val = temp->val*2+1;
					q.push(temp->left);
				}
				if (temp->right) {
					temp->right->val = temp->val*2+2;
					q.push(temp->right);
				}
			}
		}
    }
    
    bool find(int target) {
       	return node_val.find(target) != node_val.end();
    }
};
