class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       	int x=-1, y=-1;
		int n = nums.size();
		long long cnt = 0;
		int j = 0;
		for(int i=0;i<n;i++){
			if(nums[i]<minK || nums[i]>maxK){
				j = i+1;
			}
			if(nums[i]==minK)
				x = i;
			if(nums[i]==maxK)
				y = i;
			cnt+=max(0, min(x,y)-j+1);
		}
		return cnt;
    }
};
