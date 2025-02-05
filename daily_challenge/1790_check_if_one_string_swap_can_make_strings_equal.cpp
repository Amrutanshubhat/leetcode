class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       	const int n=s1.size();
		int diff=-1, cnt=0;
		for (int i=0; i<n; i++) {
			if (s1[i] != s2[i]) {
				if (cnt == 1) return false;
				if (diff == -1)
					diff = i;
				else {
					if ((s1[i] != s2[diff]) || (s2[i] != s1[diff])) 
						return false;
					cnt++;
					diff = -1;
				}
			}
		}
		return diff == -1;
    }
};
