class Solution {
	//struct comp {
	//	bool operator() (int x, int y) {
	//		return x>y;
	//	}
	//} comp;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		set<pair<float,pair<int,int>>> s;
		int n = arr.size();
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				s.insert({(float)arr[i] / arr[j], {arr[i], arr[j]}});
			}
		}
		vector<int> out(2);
		pair<int,int> tmp = (*next(s.begin(), k-1)).second;
		out[0] = tmp.first;
		out[1] = tmp.second;
		return out;
    }
};
