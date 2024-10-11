class Solution {
	struct breaker {
		bool operator()(string x, string y) {
			if (x+y < y+x) return true;
			return false;
		}
	};
public:
    string largestNumber(vector<int>& nums) {
		priority_queue<string, vector<string>, breaker> q;
		for (const auto&i: nums) {
			q.push(to_string(i));
		}
		string out;
		while(!q.empty()) {
			out += q.top();
			q.pop();
		}
		return out[0] == '0' ? out.substr(0, 1) : out;
    }
};
