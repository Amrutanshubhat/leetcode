class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
		bool inserted = false;
		for (const auto&i:intervals){
			if (newInterval[0]>=i[0] && newInterval[0]<=i[1]
				|| newInterval[1]>=i[0] && newInterval[1]<=i[1]
				|| newInterval[0]<=i[0] && newInterval[1]>=i[0]){
				newInterval[0] = min(newInterval[0],i[0]);
				newInterval[1] = max(newInterval[1],i[1]);
			}
			else if(!inserted && newInterval[0]<i[0] && newInterval[1]<i[1]) {
				inserted = true;
				out.push_back(newInterval);
				out.push_back(i);
			}
			else{
				out.push_back(i);
			}
		}
		if(!inserted){
			out.push_back(newInterval);
		}
		return out;
    }
};
