class Solution {
	vector<vector<string>> out;
    bool is_palindrome(string& s) {
        int i = 0;
        int j = s.size()-1;
        while (i<=j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

	void backtrack(string& s, int start, vector<string>& v) {
		int n = s.size();
		if (start == n) {
			out.push_back(v);
			return;
		}
		for (int i=start; i<n; i++) {
			string sub = s.substr(start, 1+i-start);
			if (is_palindrome(sub)) {
				v.push_back(sub);
				backtrack(s, i+1, v);
				v.pop_back();
			}
		}
	}
public:
    vector<vector<string>> partition(string s) {
		vector<string> v;
		backtrack(s, 0, v);
        return out;
    }
};
