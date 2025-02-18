class Solution {
	bitset<10> b;
public:
    string smallestNumber(string pattern) {
       	string out = "", cur = "";
		backtrack(pattern, cur, out);
		return out;
    }
private:
	void backtrack(string &pattern, string &cur, string &out) {
		if (!out.empty()) return;
		if (cur.size() == pattern.size()+1) {
			for (int i=0; i<pattern.size(); i++) {
				if (pattern[i] == 'I') {
					if (cur[i] > cur[i+1]) 
						return;
				} else {
					if (cur[i] < cur[i+1]) 
						return;
				}
			}
			out = cur;
			return;
		}
		for (int i=1; i<10; i++) {
			if (b[i]) continue;
			cur.push_back(i+'0');
			b[i].flip();
			backtrack(pattern, cur, out);
			b[i].flip();
			cur.pop_back();
		}
	}
};
