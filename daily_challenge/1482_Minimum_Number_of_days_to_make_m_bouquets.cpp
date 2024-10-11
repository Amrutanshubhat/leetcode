class Solution {

	bool is_bouqet(vector<int>& bloomDay, int d, int m, int k) {
		int f = 0;
		int cnt = 0;
		for (const auto&i: bloomDay) {
			if (i <= d) {
				f++;
				if (f >= k) {
					cnt++;
					f = 0;
					if (cnt >= m) return true;
				}
			}
			else {
				f = 0;
			}
		}
		return false;
	}

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
		int n = bloomDay.size();
		if (n < (long) m*k)	return -1;
			
		int min_val = INT_MAX, max_val = INT_MIN;

		for (const auto& i: bloomDay) {
			if (i < min_val) min_val = i;
			if (i > max_val) max_val = i;
		}

		while (min_val < max_val) {
			int mid = min_val + (max_val - min_val) / 2;
			if (is_bouqet(bloomDay, mid, m, k)) {
				max_val = mid;
			}
			else {
				min_val = mid+1;
			}
		}

		return min_val;
		
    }
};
