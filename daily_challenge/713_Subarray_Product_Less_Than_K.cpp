class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
		if(k<=1) return 0;
		int prod = 1;
		int cnt = 0;
		for(int l=0, r=0;r<n;r++){
			prod*=nums[r];
			while(prod>=k){
				prod/=nums[l++];
			}
			cnt+= r-l+1;
		}
		return cnt;
    }
};
