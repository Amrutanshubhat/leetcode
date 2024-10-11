class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       	int cnt = 0, odd = 0;
		int n = nums.size();

		int l = 0, r = 0, ext = 0;

		while (r<n) {
			if (nums[r] & 1) {
				odd++;
			}
			if (odd == k) cnt += ext+1;
			if (odd > k) {
				cnt++;
				l++;
				odd--;
				ext = 0;
			}
			while (odd == k) {
				if (nums[l] & 1) {
					break;
				}
				else {
					cnt++;
					ext++;
					l++;
				}
			}
			r++;
		}

		return cnt;
    }
};
