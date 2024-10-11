class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
		int out = 0;
		unordered_set<int> hs1, hs2;

		for (int x: arr1) {
			while (x > 0) {
				hs1.insert(x);
				x /= 10;
			}
		}
		for (int x: arr2) {
			while (x > 0) {
				hs2.insert(x);
				x /= 10;
			}
		}
		for (int x: hs1) {
			if (hs2.find(x) != hs2.end()) {
				int l=0;
				while (x > 0) {
					x /= 10; l++;
				}
				if (l > out) out = l;
			}
		}

		return out;
    }
};
