class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
		int xr = nums[0];
		for (int i=1; i<nums.size(); i++){
			xr ^= nums[i];
		}
		xr ^= k;
		int count = 0;
		while(xr>0) {
			if (xr%2) count++;
			xr/=2;
		}
		return count;
    }
};
