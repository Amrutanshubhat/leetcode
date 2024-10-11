class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string,vector<string> > m;
		string temp;
		for(const auto&i:s){
			temp = i;
			sort(temp.begin(),temp.end());
			m[temp].push_back(i);
		}
		vector<vector<string>> out;
		int i = 0;
		for(const auto&[key,val]:m){
			out.push_back({});
			for(const auto& w:val){
				out[i].push_back(w);
			}
			i++;
		}
		return out;
    }
};
