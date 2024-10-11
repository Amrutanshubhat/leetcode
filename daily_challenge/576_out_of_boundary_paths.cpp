class Solution {
	ll dp[51][51][51];
public:
	Solution(){memset(dp,0,sizeof(dp));}
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		if(maxMove<0 || (maxMove+startRow<m && maxMove+startColumn<n && startRow-maxMove>0 && startColumn-maxMove>0)) return 0;
		//printf("%d\t%d\t%d\n",maxMove,startRow,startColumn);
		if(startRow<0 || startColumn<0 || startRow>=m || startColumn>=n) return 1;
		if(dp[startRow][startColumn][maxMove]){
			return dp[startRow][startColumn][maxMove];
		}
		else{
			dp[startRow][startColumn][maxMove] = ((ll)((ll)findPaths(m,n,maxMove-1,startRow-1,startColumn)%MOD + (ll) findPaths(m,n,maxMove-1,startRow+1,startColumn)%MOD)%MOD +(ll) ((ll)findPaths(m,n,maxMove-1,startRow,startColumn-1)%MOD+(ll) findPaths(m,n,maxMove-1,startRow,startColumn+1)%MOD)%MOD)%MOD; 
		} 
		return dp[startRow][startColumn][maxMove];
	}
};
