class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
		int out=nums.size();
		for (int i=1; i<nums.size()-1; i++) {
			//left
			int l = longest_subsequence(nums, 0, i, comp_less);
			if (l == 1) continue;
			//right
			int r = longest_subsequence(nums, i, nums.size()-1, comp_great);
			if (r == 1) continue;

			int tot = l+r-1;
			out = min(out, (int)nums.size()-tot);
		}
		return out;
    }
private:
	inline static bool 
		comp_less(const int x, const int y) {

		return x < y;
	}
	inline static bool 
		comp_great(const int x, const int y) {

		return x > y;
	}
	int longest_subsequence(vector<int>& nums, int l, int r, bool (*cmp)(const int, const int)) {
		int n = r-l+1;
		int sorted[n];
		int cur_size = 0;
		for (int i=0; i<n; i++) {
			int tl=0, tr=cur_size-1;
			//lower bound
			while (tl <= tr) {
				int mid = tl+(tr-tl)/2;
				if (cmp(sorted[mid], nums[l+i]))
					tl = mid+1;
				else
					tr = mid-1;
			}
			if (tl == cur_size) cur_size++;
			sorted[tl] = nums[l+i];
		}
		return cur_size;
	}
};
