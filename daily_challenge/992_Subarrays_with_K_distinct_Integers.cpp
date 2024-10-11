class Solution {
	int atmost(vector<int>& nums, int k){
		if(k<1) return 0;
        int n = nums.size();
		int x = 0, y = 0;
		unordered_map<int, int> m;
		int cnt = 0;
		while(y<n){
			m[nums[y++]]++;
			if(m.size()<=k){
				continue;
			}
			while(x<y && m.size()>k){
				cnt+=y-x-1;
				m[nums[x]]--;
				if(m[nums[x]]==0){
					m.erase(nums[x]);
				}
				x++;
			}
		}
		while(x<y && m.size()<=k){
			cnt+=y-x;
			m[nums[x]]--;
			if(m[nums[x]]==0){
				m.erase(nums[x]);
			}
			x++;
		}
		return cnt;
	}
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
		return atmost(nums, k)-atmost(nums, k-1);
    }
};
