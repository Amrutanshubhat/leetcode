class Solution {
	void quicksort(vector<int>& arr, int l, int r) {
		if (l >= r || l<0) return;
		int p = partition(arr, l, r);
		quicksort(arr, l, p);
		quicksort(arr, p+1, r);
	}

	int partition(vector<int>& arr, int l, int r) {
		int pivot = arr[l];
		l--; r++;
		while (1) {

			while (arr[++l] < pivot);
			while (arr[--r] > pivot);

			if (l >= r) return r;
			 //swap
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
	}

public:
    vector<int> sortArray(vector<int>& nums) {
    	quicksort(nums, 0, nums.size()-1);
		return nums;
    }
};
