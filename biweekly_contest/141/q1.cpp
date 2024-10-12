class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
		vector<int> out;

		for (auto num: nums) {
			if (num == 2) {
				out.push_back(-1);
				continue;
			}
			size_t x = 0;
			size_t val = 0;
			while (num & 1) {
				num >>= 1;
				val |= 1 << x++;
			}
			val >>= 1;
			while (num) {
				val |= (num & 1) << x++;
				num >>= 1;
			}
			out.push_back(val);
		}
		return out;
    }
};
