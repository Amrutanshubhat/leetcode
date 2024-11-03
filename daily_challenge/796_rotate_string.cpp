class Solution {
public:
    bool rotateString(string s, string goal) {
       	size_t m=s.size(), n=goal.size();
		if (m != n) return false;

		for (size_t i=0; i<m; i++) {
			while (i<n && s[0] != goal[i]) i++;
			size_t cnt=1, j=(i+1)%n;
			while (cnt != n && s[cnt]==goal[j]) {
				j = (j+1)%n;
				cnt++;
			}
			if (cnt == n) return true;
		}
		return false;
    }
};
