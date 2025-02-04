class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
		const int n = nums.size();
		int max_tot = nums[0];
		for (int i=1, tot=nums[0]; i<n; i++) {
			if (nums[i] > nums[i-1])
				tot += nums[i];
			else
				tot = nums[i];
			max_tot = max(max_tot, tot);
		}
		return max_tot;

    }
};
