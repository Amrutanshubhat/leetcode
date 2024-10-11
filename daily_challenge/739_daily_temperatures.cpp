class Solution{
	public:
		vector<int> dailyTemperatures(vector<int>& temperatures) {
        	stack<pair<int,int>> s;
			int n = temperatures.size();
			vector<int> out(n);
			//s.push(temperatures[0]);
			for(int i=0;i<n;i++){
				while(!s.empty() && s.top().first<temperatures[i]){
					out[s.top().second] = i - s.top().second;s.pop();
				}
				s.push({temperatures[i],i});
			}
			return out;
		}
};
