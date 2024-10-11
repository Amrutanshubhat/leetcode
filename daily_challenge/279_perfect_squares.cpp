class Solution{
	
	public:
		int numSquares(int n) {
        	int dp[n+1];
			dp[0] = 0;
			int sq = sqrt(n);
			int arr[sq+1];
			for (int i=1;i<=sqrt(n);i++){
				arr[i] = pow(i,2);
			}

			for(int i=1;i<=n;i++){
				dp[i] = INT_MAX;
				for(int j=sq;j>0;j--){
					if(arr[j]>i) continue;
					int count = (i/arr[j]) + dp[i%arr[j]];
					dp[i] = min(dp[i],count);
				}
			}
			return dp[n];
    	}

};
