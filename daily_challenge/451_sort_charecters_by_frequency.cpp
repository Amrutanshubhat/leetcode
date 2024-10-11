class Solution {
public:
    string frequencySort(string s) {
        int arr[128] = {0};
		for(const char& c:s){
			arr[c]++;
		}
		multimap<int,char,greater<int>> m;
		for(int i=0;i<128;i++){
			if(arr[i]>0){
				m.insert({arr[i],(char) i});
			}
		}
		string out;
		for(const auto&[f,c]:m){
			out.append(f,c);
		}
		return out;
    }
};
