class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
		const int n = nums.size();
		int out = 1;
		int dec=1, inc=1;
		for (int i=1; i<n; i++) {
			if (nums[i] < nums[i-1]) {
				dec++;
				inc = 1;
			} else if (nums[i] > nums[i-1]) {
				inc++;
				dec = 1;
			} else {
				inc = dec = 1;
			}
			out = max(out, max(inc, dec));
		}
		return out;
    }
};
