class Solution {
	size_t out;
	size_t limit;
	size_t dist() {
		size_t d = 0;
		size_t a = out, b = out+1;
		while (a <= limit) {
			d += min(limit+1, b)-a;
			a *= 10; b *= 10;
		}
		return d;
	}
public:
    int findKthNumber(int n, int k) {
		out = 1;
		limit = n;
		for (size_t i=1; i<k;) {
			size_t d = dist();
			if (i+d <= k) {
				i += d;
				out++;

			} else {
				i++;
				out *= 10;
			}
		}
		return out;
    }
};
