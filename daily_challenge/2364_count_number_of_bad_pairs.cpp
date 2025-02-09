class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
		const int n = nums.size();
       	unordered_map<int, int> ht;
		for (int i=0; i<n; i++) {
			ht[i-nums[i]]++;
		}
		auto sum_n = [](int n)->size_t {
			return ((size_t)n*(n-1))/2;
		};
		size_t tot=0;
		for (const auto&[diff, cnt]: ht) {
			tot += sum_n(cnt);
		}
		return sum_n(n) - tot;
    }
};
