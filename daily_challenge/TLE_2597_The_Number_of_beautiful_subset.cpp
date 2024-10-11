class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
		int n = nums.size();
		int count = 0;
		sort(nums.begin(), nums.end());

		for (int i=0; i<(1<<n); i++) {
			vector<bool> cnt(nums[n-1]);
			bool inc = true;
			for (int j=0; j<n; j++) {
				if (i & (1<<j)) {
					if (nums[j]-k > 0 && cnt[nums[j]-k]) {
						inc = false;
						break;
					}
					cnt[nums[j]] = true;
				}
			}
			if (inc)
				count++;
		}
		return count-1;
    }
};
