class Solution {
#define ARR_LEN 100001
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    	int arr[ARR_LEN] = {0}; 
		size_t n=nums.size();
		size_t tot = 0, out=0;
		for (int i=0, j=0; i<n-k+1; i++) {
			while (j-i < k && arr[nums[j]] == 0) {
				arr[nums[j]]++;
				tot += nums[j++];
			}
			if (j-i == k) {
				out = max(out, tot);
			}
			tot -= nums[i];
			arr[nums[i]]--;
		}
		return out;
    }
};
