class Solution{
	
	public:
		vector<int> largestDivisibleSubset(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> arr(n);
			//sort(nums.begin(),nums.end());
			int max_len = 0;
			for(int i=0;i<n;i++){
				arr[i].push_back(nums[i]);
				for(int j=i-1;j>=0;j--){
					if(nums[i]%nums[j] == 0){
						if(arr[i].size()<arr[j].size()+1){
							arr[i] = arr[j];
							arr[i].push_back(nums[i]);
						}
					}
				}
				if(arr[i].size()>max_len)
					max_len = arr[i].size();
			}
			int x = 0;
			while(x<n){
				if(arr[x].size()==max_len) break;
				x++;
			}
			return arr[x];
    	}
		

};
