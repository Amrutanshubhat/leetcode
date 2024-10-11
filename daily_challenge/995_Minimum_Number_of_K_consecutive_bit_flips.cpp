class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
       	int n = nums.size(); 
		int cnt = 0;
		int flip = 0;
		for (int i=0; i<n; i++) {
			if (i>=k && nums[i-k] == 2) {
				//processed val
				flip--;
			}
			if ((flip & 1) == nums[i]) {
				if (i+k > n) return -1;
				cnt++;
				flip++;
				nums[i] = 2;
			}
		}
		return cnt;
    }
};
