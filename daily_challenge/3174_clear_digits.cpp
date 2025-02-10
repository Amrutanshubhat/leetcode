class Solution {
public:
    string clearDigits(string s) {
		string out;
		for (const auto&c: s) {
			if (isdigit(c))
				out.pop_back();
			else
				out.push_back(c);
		}
		return out;
    }
};
