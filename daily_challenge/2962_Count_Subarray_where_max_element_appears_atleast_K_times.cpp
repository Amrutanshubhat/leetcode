class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int val = *max_element(nums.begin(), nums.end());
		int n = nums.size();
		long long cnt = 0;
		int m = 0;
		for(int i=0, j=0;j<n;j++){
			if(nums[j]==val)
				m++;
			if(m>=k){
				cnt+=i-0+1;
			}
			while(j>i && m>=k){
				if (nums[i] == val){
					if(m==k) break;
					m--;
				}
				cnt++;
				i++;
			}
		}
		return cnt;
    }
};
