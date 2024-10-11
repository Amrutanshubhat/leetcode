class Solution {
public:
    int pivotInteger(int n) {
    	int arr[n+1];
		arr[0] = 0;
		for(int i=1;i<=n;i++){
			arr[i]=i+arr[i-1];
		}
		for(int i=1;i<=n;i++){
			if(arr[i-1] == arr[n]-arr[i]) return i;
		}
		return -1;
    }
};
