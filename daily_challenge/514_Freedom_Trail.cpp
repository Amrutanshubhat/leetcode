class Solution {
	int get_d(int n, int x, int y) {
		return min(abs(x-y), n-max(x,y)+min(x,y));
	}
public:
    int findRotateSteps(string ring, string key) {
		int n = ring.size();

		/*
		 * each key, index of char in ring, total steps 
		 * */

		vector<vector<pair<int,int>>> dp(key.size());
		int ind = 0;
	
		unordered_map<char, vector<int>> m;
		for(int i=0; i<n; i++) {
			m[ring[i]].push_back(i);
		}

		//for first index
		for (const auto&i: m[key[ind]]){
			int d = get_d(n, 0, i);
			dp[ind].push_back({i, d+1}); //+1 to push the button
		}
		ind++;
		while(ind < key.size()) {
			for (const auto&i: m[key[ind]]) {
				int min_d = INT_MAX;
				for (const auto&[j, d]: dp[ind-1]) {
					min_d = min(min_d, d+get_d(n, i, j));
				}
				dp[ind].push_back({i, min_d+1});
			}
			ind++;
		}
		int out = INT_MAX;
		for (const auto&[i,d]:dp[ind-1]){
			cout<<i<<" "<<d<<" "<<"\n";
			if (out>d) out = d;
		}
		return out;
    }
};
