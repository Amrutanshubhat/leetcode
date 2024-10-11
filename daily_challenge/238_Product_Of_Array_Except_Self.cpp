class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
		int a[n], b[n];
		
		//base condition
		a[0] = 1;
		b[n-1] = 1;

		//prefix array
		for(int i=1;i<n;i++){
			a[i] = nums[i-1]*a[i-1];
		}

		//suffix array
		for(int i=n-2;i>=0;i--){
			b[i] = nums[i+1]*b[i+1];
		}
		vector<int> out(n);
		
		//prefix*suffix
		for(int i=0;i<n;i++){
			out[i] = a[i]*b[i];
		}
		return out;
    }
};
