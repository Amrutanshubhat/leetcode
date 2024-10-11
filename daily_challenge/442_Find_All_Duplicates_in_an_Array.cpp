class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int> out;
		for(int i=0;i<n;i++){
			// cycle_sort logic
			// if the expected spot is not current spot and
			// the spot is already accupied by the right element
			// append the duplicate to reault array and replace duplicate element's spot with -1.
			// Otherwise swap the elemnt to it's expected place.
			while(nums[i]!=-1 && i+1!=nums[i]){
				if(nums[nums[i]-1]==nums[i] && nums[i] != i+1){
					out.push_back(nums[i]);
					nums[i] = -1;
					break;
				}
				else{
					swap(nums[i], nums[nums[i]-1]);
				}
				print_array(nums);
			}
		}
		return out;
    }
};
