class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       	priority_queue<size_t, vector<size_t>, greater<size_t>> pq;
		for (const auto&num: nums)
			pq.push(num);

		int op=0;
		while (pq.top() < k) {
			size_t a = pq.top(); pq.pop();
			size_t b = pq.top(); pq.pop();
			pq.push(a*2+b);
			op++;
		}
		return op;
    }
};
