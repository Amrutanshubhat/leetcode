class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
		int m[k];
		memset(m, 0, sizeof(m));
		for (const auto& i: arr) {
			m[((i%k)+k)%k]++;
		}
		if (m[0]%2) return false;
		for (int i=1; i<k/2; i++) {
			if (m[i] != m[k-i])	return false;
		}
		return true;
    }
};
