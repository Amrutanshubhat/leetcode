class Solution {
	vector<int> out;
	int limit;
	void rec(int x) {
		if (x > limit) return;
		out.push_back(x);
		for(int i=0; i<10; i++) {
			int nex = (x*10)+i;
			if (nex>limit) break;
			rec(nex);
		}
	}
public:
    vector<int> lexicalOrder(int n) {
		limit = n;
		for (int i=1; i<10 && i <= n; i++) {
			rec(i);
		}
		return out;
    }
};
