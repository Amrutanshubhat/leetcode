class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       	int x=0;
		if (nums1.size() & 1)
			for (const auto&num: nums2) 
				x ^= num;
		if (!(nums2.size() & 1)) return x;
		int out=0;
		for (const auto&num: nums1)
			out ^= num^x;

		return out;
    }
};
