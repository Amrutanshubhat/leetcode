class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
		int max_tot = 0, min_tot=0, atot=0, btot=0;
		for (const auto& num: nums) {
			atot = max(num, atot+num);
			btot = min(num, btot+num);
			if (atot > max_tot) max_tot = atot;
			if (btot < min_tot) min_tot = btot;
		}
		return max(max_tot, abs(min_tot));
    }
};
