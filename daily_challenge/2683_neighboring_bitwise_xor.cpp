class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
       	int x=0;
		for (const auto&num: derived)
			x ^= num;
		return x==0;
    }
};
