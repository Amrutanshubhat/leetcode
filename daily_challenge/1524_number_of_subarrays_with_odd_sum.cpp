class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
		constexpr int MOD = 1e9+7;

		int ps=0, out=0, odd=0, even=1;

		for (const auto&num: arr) {
			ps += num;
			if (ps & 1) {
				out += even;
				odd++;
			} else {
				out += odd;
				even++;
			}
			out %= MOD;
		}
		return out;
    }
};
