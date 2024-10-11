class Solution {
	int bsearch(vector<int>& position, int n, int f) {
		int balls = 1;
		int pos = 0;
		for (int i=1; i<n; i++) {
			if (position[i] - position[pos] >= f) {
				pos = i;
				balls++;
			}
		}
		return balls;
	}
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
		sort(position.begin(), position.end());
		
		int l = 1;
		int r = position[n-1] - position[0];

		while (l < r) {
			int mid = l + 1 + (r - l)/2;
			if (bsearch(position, n, mid) >= m) {
				l = mid;
			}
			else {
				r = mid-1;
			}
		}

		return l;
    }
};
