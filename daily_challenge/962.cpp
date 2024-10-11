class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       	stack<int> s; 
		s.push(0);
		size_t n = nums.size();
		for (size_t i=1; i<n; i++) {
			if (nums[i] < nums[s.top()]) {
				s.push(i);
			}
		}
		size_t width = 0;
		for (size_t i=n-1; !s.empty(); i--) {
			while (!s.empty() && nums[s.top()] <= nums[i]) {
				width = max(width, i - s.top());
				s.pop();
			}
		}
		return width;
    }
};
