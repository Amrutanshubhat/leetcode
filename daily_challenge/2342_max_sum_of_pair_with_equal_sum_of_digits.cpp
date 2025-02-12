class Solution {
public:
    int maximumSum(vector<int>& nums) {
		unordered_map<int, priority_queue<int>> ht;

		auto DigitSum = [](int n)->int {
			int tot = 0;
			while (n) {
				tot += n%10;
				n /= 10;
			}
			return tot;
		};

		for (const auto&num: nums) {
			ht[DigitSum(num)].push(num);
		}

		int out=-1;
		for (auto&[_, q]: ht) {
			if (q.size() < 2) continue;
			int a = q.top(); q.pop();
			int b = q.top();
			out = max(out, a+b);
		}
		return out;
    }
};
