class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
		sort(nums.begin(),nums.end());
		long long tot = 0;
		for(const auto&i:nums){
			tot+=i;
		}

		for (int i=n-1;i>=0;i--){
			if(tot-nums[i]<=nums[i]){
				if(i<3) return -1;
				tot-=nums[i];
			}
			else break;
		}
		return tot;
    }
};
