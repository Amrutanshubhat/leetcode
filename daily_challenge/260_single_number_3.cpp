class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       	unsigned int x = 0;
		vector<int> out(2);
		for(const auto&i:nums) {
			x^=i;
		}
		const unsigned int l = x&-x;
		for (const auto&i:nums) {
			if (l & i)
				out[0] ^= i;
			else
			 out[1] ^= i;
		}
		return out;
    }
};
