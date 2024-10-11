class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26] = {0};
		for(const auto&c:tasks){
			arr[c-'A']++;
		}
		sort(arr,arr+26);
		//idle time
		int clock = (arr[25]-1) * n;
		clock+=arr[25];
		for(int i=24;i>=0;i--){
			if(arr[i]==arr[25]){
				clock++;
			}
			else{
				break;
			}
		}
		return max(int(tasks.size()),clock);
    }
};
