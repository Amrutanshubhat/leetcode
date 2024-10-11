class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
		int max_min = 24*60;
		int n = timePoints.size();
		vector<int> minutes;
		for (const auto&hm: timePoints) {
			int m = (stoi(hm.substr(0, 2))*60) + stoi(hm.substr(3,2));
			minutes.push_back(m);	
		}
		sort(minutes.begin(), minutes.end());
		int out = INT_MAX;
		for (int i=0; i<n; i++) {
			int nex = (i+1)%n;
			int diff = min(abs(minutes[i]-minutes[nex]), (max_min-minutes[i]) + minutes[nex]);
			if (diff < out) out = diff;
		}
		return out;
    }
};
