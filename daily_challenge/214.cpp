class Solution {
public:
    string shortestPalindrome(string s) {
		const string x {s.rbegin(), s.rend()};
       	const string_view ss(s);
		const string_view sx(x);
		size_t n = s.size();
		for (size_t i=0; i<n; i++) {
			if (ss.substr(0, n-i) == sx.substr(i))	{
				return x.substr(0, i)+s;
			}
		}
		return x+s;
    }
};
