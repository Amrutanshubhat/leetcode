class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
		unordered_map<int,int> hash;
		hash[0] = 1;
		int tot = 0;
		int count = 0;
		for(const auto& i:nums){
			tot+=i;
			count+=hash[tot-goal];
			hash[tot]++;
		}
		return count;
    }
};
