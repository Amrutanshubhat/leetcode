class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
		int max_cnt = 0;
		unordered_map<int,int> m;
		for(int i=0,j=0; j<n; j++){
			while(j>i && m[nums[j]]>=k){
				m[nums[i++]]--;
			}
			m[nums[j]]++;
			max_cnt = max(max_cnt, j-i+1);
		}
		return max_cnt;
    }
};
