class Solution {
	string out;
	int count;
public:
    string getHappyString(int n, int k) {
		string s = "";
		count = 0;
       	dfs(s, n, k);	 
		return out;
    }
private:
	void dfs(string &s, int n, int k) {
		if (s.size() == n) {
			if (++count == k)
				out = s;
		} else if (out.empty()) {
			for (int i=0; i<3; i++) {
				char c = 'a'+i;
				if (s.empty() || s.back() != c) {
					s.push_back(c);
					dfs(s, n, k);
					s.pop_back();
				}
			}
		}
	}
};
