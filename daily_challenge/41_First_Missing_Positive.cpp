class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		int x = 0;
		// put the val in its expected place
		// val that does not belong at it's index is the output
		// or the n+1th element if all belong at their place
		while(x<n){
			if(nums[x]>0 && nums[x]<=n && nums[x]!=nums[nums[x]-1])
				swap(nums[x], nums[nums[x]-1]);
			else
				x++;
		}
		for(int i=1;i<=n;i++){
			if(nums[i-1]!=i)
				return i;
		}
  		return n+1;      
    }
};
