class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
 		int n = arr.size();
		unordered_map<int,int> m;
		for(const auto&i:arr){
			m[i]++;
		}
	
		vector<int> p;
		for(const auto& [val,cnt]:m){
			p.push_back(cnt);
		}
		sort(p.begin(),p.end());
		int x=0;
		while(k>0){
			if(p[x]>k) break;
			else{
				k-=p[x];
				x++;
			}
			//cout<<x<<" "<<k<<endl;
		}
		return p.size()-x;
    }
};
