class Solution {
	unordered_set<string> st;
	size_t max_sub;
public:
    int maxUniqueSplit(string s) {
		max_sub = 0;
		dfs(s, 0);
		return max_sub;
    }

private:
	void dfs(string& s, int x) {
		if (x == s.size()) {
			max_sub = max(max_sub, st.size());
			return;
		}
		for (size_t i=x; i<s.size(); i++) {
			string temp{s.substr(x, i-x+1)};
			if (st.find(temp) == st.end()) {
				st.insert(temp);
				dfs(s, i+1);
				st.erase(temp);
			}
		}
	}
};
