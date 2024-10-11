class Solution {
public:
    int minSwaps(string s) {
		int close = 0, open = 0;
		size_t swap = 0, n = s.size();
		for (size_t p=0, q=n-1; p < q; p++) {
			if (s[p] == '[') open++;
			else close++;

			if (open < close) {
				while (s[q--] == ']');
				close--;
				open++;
				swap++;
			}
		}
		return swap;
    }
};
