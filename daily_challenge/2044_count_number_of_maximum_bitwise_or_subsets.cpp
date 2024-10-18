class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
		int maxor = 0;
		for (const auto&num: nums) maxor |= num;
		int count = 0;
		size_t subsets = (1<<nums.size())-1; //ignore empty set
		for (size_t i=1; i<=subsets; i++) {
			int tempor = 0;
			for (size_t j=0; j<nums.size(); j++) {
				if (i & (1<<j)) {
					tempor |= nums[j];
				}
			}
			if (tempor == maxor) count++;
		}
		return count;
    }
};
