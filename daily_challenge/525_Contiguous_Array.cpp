class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int,int> m;
		int tot = 0;
		int max_len = 0;
		for(int i=1;i<=n;i++){
			if(nums[i-1]) tot++;
			else tot--;
			//all elements from start
			if(tot==0){
				max_len = i;
			}
			//first occurence
			else if(!m[tot]){
				m[tot] = i;
			}
			//potential match
			else{
				max_len = max(max_len, i-m[tot]);
			}
		}
		return max_len;
    }
};
