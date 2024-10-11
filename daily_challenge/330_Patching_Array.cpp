class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    	int out = 0;
		long long covered = 0;
		int j = 0;
		int sz = nums.size();
		while (covered < n) {
			if (j<sz && covered+1>=nums[j]) {
				covered += nums[j++];
			}
			else {
				covered += covered+1;
				out++;
			}
		}
		return out;
    }
};
