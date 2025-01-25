class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
		auto arr = nums;
		sort(arr.begin(), arr.end());
		
		unordered_map<int, multiset<int>> ht;
		unordered_map<int, int> idx;
		ht[0].emplace(arr[0]);
		idx[nums[0]] = 0;
		for (int i=1, g=0; i<arr.size(); i++) {
			if (arr[i]-arr[i-1] > limit) {
				g++;
			}
			idx[arr[i]] = g;
			ht[g].emplace(arr[i]);
		}
		vector<int> out;
		for (int i=0; i<nums.size(); i++) {
			int g = idx[nums[i]];
			out.push_back(*(ht[g].begin()));
			ht[g].erase(ht[g].begin());
		}
		return out;
    }
};
