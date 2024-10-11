class Solution {
public:
    string customSortString(string order, string s) {
  		int arr[26] = {0};
		for(const auto& c:s){
			arr[c-'a']++;
		}
		string out;
		for(const auto&c:order){
			while(arr[c-'a'] > 0){
				out.push_back(c);
				arr[c-'a']--;
			}
		}
		for(int i=0;i<26;i++){
			while(arr[i]>0){
				out.push_back(i+'a');
				arr[i]--;
			}
		}
		return out;
    }
};
