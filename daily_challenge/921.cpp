class Solution {
public:
    int minAddToMakeValid(string s) {
    	size_t n = s.size();

		int open=0;
		int cnt = 0;
		
		for (size_t p=0; p<n; p++) {
			if (s[p] == '(') {
				open++;
			} else {
				open--;
				if (open < 0) {
					open++;
					cnt++;
				}
			}
		}
		cnt += abs(open);
		return cnt;
    }
};
