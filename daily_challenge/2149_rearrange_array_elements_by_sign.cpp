class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
		int n = nums.size();
		int x = 0;
		int y = 1;
		vector<int> out(n);
		for(const auto&i:nums){
			if(i<0){
				out[y] = i;
				y+=2;
			}
			else{
				out[x] = i;
				x+=2;
			}
		}
		return out;
    }
};
