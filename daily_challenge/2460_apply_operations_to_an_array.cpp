class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
		const int n = nums.size();
		vector<int> out(n);
		int k=0;
		for (int i=0; i<n-1; i++) {
			if (!nums[i]) continue;
			if (nums[i] == nums[i+1]) {
				out[k++] = nums[i]*2;
				nums[i+1] = 0;
				i++;
			} else {
				out[k++] = nums[i];
			}
		}
		if (nums[n-1]) out[k] = nums[n-1];
		return out;
    }
};
