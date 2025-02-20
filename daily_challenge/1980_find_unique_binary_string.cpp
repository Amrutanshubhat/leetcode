class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       	const int n = nums.size();
		unordered_set<long> st;

		for (const auto& num: nums) {
			int x=0;
			for (int i=0; i<n; i++) {
				int val = num[i]-'0';
				x |= (val << (n-i-1));
			}
			st.insert(x);
		}
		string out;
		for (int i=0; i<1<<n; i++) {
			uint x=0;
			for (int j=0; j<n; j++) {
				if (1 & (i>>j)) {
					x |= (1<<j);
				}
			}
			if (st.find(x) == st.end()) {
				for (int j=n-1; j>=0; j--) {
					out += to_string((x>>j)&1);
				}
				return out;
			}
			st.insert(x);
		}
		return out;
    }
};
