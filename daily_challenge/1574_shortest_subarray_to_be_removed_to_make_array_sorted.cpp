class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
		int n = arr.size();
		int f=1, b=1;

		for (int i=n-2; i >= 0; i--) {
			if (arr[i] > arr[i+1])
				break;
			b++;
		}

		for (int i=1; i<n; i++) {
			if (arr[i] < arr[i-1])
				break;
			f++;
		}
		int out = max(b, f);

		for (int i=max(n-b, f); i<n; i++) {
			int index = upper_bound(arr.begin(), arr.begin()+f, arr[i]) - arr.begin();
			if (index != 0) {
				out = max(index+n-i, out);
			}
		}
		return n-out;
    }
};
