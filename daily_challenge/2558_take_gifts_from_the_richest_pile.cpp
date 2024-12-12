class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
       	priority_queue<int> q;
		for(const auto&gift: gifts) {
			q.emplace(gift);
		}
		int top;
		while (k-- && (top=q.top()) > 1) {
			q.pop();
			q.push(sqrt(top));
		}	
		size_t out = 0;
		while (!q.empty()) {
			out += q.top(); q.pop();
		}
		return out;
    }
};
