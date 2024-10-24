class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		//bfs at same time
		queue<TreeNode*> q1, q2;
		q1.push(root1);
		q2.push(root2);
		// for empty tree
		if (q1.front() != nullptr)
			q1.push(nullptr);
		if (q2.front() != nullptr)
			q2.push(nullptr);
		while (!q1.empty() && !q2.empty()) {
			TreeNode* t1 = q1.front(), *t2 = q2.front();
			q1.pop(); q2.pop();

			if (t1 == nullptr or t2 == nullptr) {
				if (t1 != t2) 
					return false;
				if (!q1.empty()) q1.push(t1);
				if (!q2.empty()) q2.push(t2);

			} else {
				if (t1->val != t2->val) return false;
				//flip if needed
				if ((t1->left == nullptr && t2->left != nullptr) ||
						(t1->left != nullptr && t2->left == nullptr) ||
						((t1->left != t2->left) && (t1->left->val != t2->left->val))) {
					swap_node(&t1->left, &t1->right);
				}
				if (t1->left != t2->left) {
					if (t1->left == nullptr || t2->left == nullptr)
						return false;
					q1.push(t1->left); q2.push(t2->left);
				}
				if (t2->right != t1->right) {
					if (t1->right == nullptr || t2->right == nullptr)
						return false;
					q2.push(t2->right); q1.push(t1->right);
				}
			}
		}
		if (q1.empty() && q2.empty()) return true;
		return false;
    }
private:
	inline void swap_node(TreeNode** t1, TreeNode** t2) {
		TreeNode* temp = *t1;
		*t1 = *t2;
		*t2 = temp;
	}
};
