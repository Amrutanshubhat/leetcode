class Solution {
	bool is_vowel(char c) {
		return c == 'a' || c == 'e' || c=='i' || c == 'o' || c == 'u';
	}
public:
    int findTheLongestSubstring(string s) {
		size_t n = s.size();
		size_t maxd = 0;
		unordered_map<size_t, int> h{{0, -1}};
		size_t p = 0;
		for (size_t i=0; i<n; i++) {
			if (is_vowel(s[i])) {
				p ^= (1 << (s[i]-'a'));
			}
			if (h.find(p) == h.end()) {
				h[p] = i;
			}
			if (maxd < i-h[p]) {
				maxd = i-h[p];
			}
		}
		return maxd;
    }
};
