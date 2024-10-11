class Solution {
#define ALPH 26
public:
    bool checkInclusion(string s1, string s2) {
       	int dp[ALPH] = {0};
		for (const auto&c: s1) {
			dp[c-'a']++;
		}
		size_t m = s1.size(), n = s2.size();
		if (m > n) return false;
		for (int i=0; i<m; i++) {
			dp[s2[i]-'a']--;
		}
		if (is_equal(dp)) return true;
		for (int i=0, j=m; j<n; i++, j++) {
			dp[s2[i]-'a']++;
			dp[s2[j]-'a']--;
			if (is_equal(dp)) return true;
		}
		return false;

    }
private:
	bool is_equal(int* arr) {
		for (int i = 0; i<ALPH; i++) {
			if (arr[i] != 0) return false;
		}
		return true;
	}
};
