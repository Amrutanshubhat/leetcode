class Solution {
public:
    string removeOccurrences(string s, string part) {
		const int n = part.size();
       	while (true) {
			auto it = s.find(part);
			if (it == s.npos) break;
			s.erase(s.begin()+it, s.begin()+it+n);
		}
		return s;
    }
};
