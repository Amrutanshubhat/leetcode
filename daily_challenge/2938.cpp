class Solution {
	//p points to first out of order 1
	//q points to first out of order 0
public:
    long long minimumSteps(string s) {
       	size_t n=s.size(), p=0, q=0, swap=0;
		while (p<n && s[p] == '0') p++;
		if (p==n) return swap;
		while (q<n) {
			if (s[q] == '0' && q>p) {
				swap += q-p;
				p++;
			}
			q++;
		}
		return swap;
    }
};
