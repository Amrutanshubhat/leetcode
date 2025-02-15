class Solution {
public:
    int punishmentNumber(int n) {
		int out = 0;
		for (int i=1; i<=n; i++) {
			string s = to_string(i*i);
			if (dfs(s, "", 0, i, 0)) {
				out += stoi(s);
			}
		}
		return out;

    }
private:
	bool dfs(string &s, string cur, int idx, int original, int tot) {
		if (idx == s.size())  {
			if (tot == original) return true;
			return false;
		}
		string sub = "";
		for (int i=idx; i<s.size(); i++) {
			sub.push_back(s[i]);
			if (dfs(s, cur+sub, i+1, original, tot+stoi(sub))) return true;
		}
		return false;
	}
};
