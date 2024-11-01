class Solution {
public:
    string makeFancyString(string s) {
		string out{s.substr(0,2)};
		for (size_t i=2; i<s.size(); i++) {
			if (s[i] == s[i-1] && s[i] == s[i-2]) 
				continue;
			out.push_back(s[i]);
		}
		return out;
    }
};
