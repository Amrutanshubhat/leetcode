class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
		/* could be implemented using monotonic stack but the below solution takes only constant space*/
       	int n = nums.size();
		int out = 0;
		
		int j = 0, max_val = nums[0], min_val = nums[0];
		for (int i=0; i<n; i++) {
			if (max(abs(nums[i] - max_val), abs(nums[i] - min_val)) > limit) {
				max_val = nums[i];
				min_val = nums[i];
				for (j = i-1; j>=0; j--) {
					if (abs(nums[i] - nums[j]) > limit) {
						j++;
						break;
					}
					min_val = min(min_val, nums[j]);
					max_val = max(max_val, nums[j]);
				}
			}
			min_val = min(min_val, nums[i]);
			max_val = max(max_val, nums[i]);

			out = max(out, i-j+1);
		}
		return out;
    }
};
