class Solution {
public:
    int countTriplets(vector<int>& arr) {
		int n = arr.size();
		int cnt = 0;

		vector<vector<int>> v(n, vector<int>(n));
		for (int i=0; i<n-1; i++) {
			int val = arr[i];
			for (int j=i+1; j<n; j++) {
				val^=arr[j];
				v[i][j] = val;
			}
		}

		for (int i=0; i<n-1; i++) {
			for (int j=i+1; j<n; j++) {
				if (v[i][j] == 0) {
					cnt+=j-i;
				}
			}
		}
		return cnt;
    }
};
