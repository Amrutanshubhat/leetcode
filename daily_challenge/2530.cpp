class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    	priority_queue<int> q;    
		for (const auto&num: nums) {
			q.push(num);
		}
		size_t out = 0;
		while (k--) {
			out += q.top();
            int val = (int)ceil((double)q.top()/3);
			q.pop();
            q.push(val);
		}
		return out;
    }
};
