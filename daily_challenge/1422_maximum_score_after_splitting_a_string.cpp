class Solution {
public:
    int maxScore(string s) {
		const size_t n=s.size();
		int ht[n];
		memset(ht, 0, sizeof(ht));
		int out=0;	
		for (int i=0, z=0, one=0; i<n; i++) {
			if (s[i] == '0')
				++z;
			if (s[n-i-1] == '1')
				++one;
			ht[i] += z;
			ht[n-i-1] += one;
		}
		if (s.back() == '0') ht[n-1]--;
		if (s.front() == '1') ht[0]--;
		for (int i=0; i<n; i++)
			if (ht[i] > out)  out=ht[i];

		return out;
    }
};
