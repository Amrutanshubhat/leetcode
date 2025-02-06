class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
		const int n = nums.size();
		unordered_map<int, int> ht;
		int out=0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				ht[nums[i]*nums[j]]++;
			}
		}
		auto C = [](int n, int r)->int {
			r = max(r, n-r);
			auto fact = [](int x, int y)->size_t {
				size_t out = 1;
				for (int i=x; i>y; i--)
					out *= i;
				return out;
			};
			return fact(n, n-r)/fact(r, 1);
		};

		for (const auto&[k, val]: ht) {
			if (val > 1) {
				out += 8*C(val, 2);
			}
		}
		return out;
    }
};
