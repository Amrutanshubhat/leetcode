class Solution {
	void increment(string& s, bool& carry) {
		for (int i=s.size()-1; i>=0; i--) {
			if (s[i] == '1') {
				s[i] = '0';
			}
			else {
				s[i] = '1';
				return;
			}
		}
		carry = true;
	}
public: 
    int numSteps(string s) {
		int steps = 0;
		bool carry = false;
		while (s.size()>1) {
			if (s[s.size()-1] == '1') {
				increment(s, carry);
			}
			else {
				s.pop_back();
			}
			steps++;
			if (carry) {
				steps+=s.size();
				break;
			}
		}
		return steps;
    }
};
