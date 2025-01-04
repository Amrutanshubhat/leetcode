class Solution {
public:
    int countPalindromicSubsequence(string s) {
		size_t n=s.size();
		constexpr int ASIZE=26;
		vector<vector<int>> ps(n+1, vector<int>(ASIZE));
		vector<pair<int, int>> arr(ASIZE);
		for (size_t i=1; i<=n; i++) {
			for (size_t j=0; j<ASIZE; j++) {
				ps[i][j] = ps[i-1][j];
			}
			int idx=s[i-1]-'a';
			ps[i][idx]++;
			if (arr[idx].first == 0) {
				arr[idx].first = i;
			} else {
				arr[idx].second = i;
			}

		}
		int cnt=0;
		for (const auto&p: arr) {
			if (p.first == 0 || p.second == 0) continue;
			for (int i=0; i<ASIZE; i++) {
				if (ps[p.second][i] > ps[p.first][i])
					cnt++;
			}
			int idx=s[p.first-1]-'a';
			if (ps[p.second][idx]-ps[p.first][idx] == 1) cnt--; //overcount
		}
		return cnt;
    }
};
