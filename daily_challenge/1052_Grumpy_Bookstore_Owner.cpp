class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		/*
			* prefix sum to store customer and happy count at each minute
			* slide the window of width minutes and store max possible happy customers
		*/

 		int max_hap;
		int n = customers.size();
		vector<int> prefix(n+1), happy(n+1);

		for(int i=1; i<=n; i++) {
			prefix[i] = customers[i-1] + prefix[i-1];
			happy[i] = happy[i-1];
			if (!grumpy[i-1])
				happy[i] += customers[i-1];
		}
		max_hap = happy[n];

		for (int i=1; i<=n; i++) {
			int last = max(1+i-minutes, 1);
			int cur_happy = happy[last-1] + prefix[i] - prefix[last-1];
			max_hap = max(max_hap, happy[n]+(cur_happy - happy[i]));
		}
		return max_hap;
    }
};
