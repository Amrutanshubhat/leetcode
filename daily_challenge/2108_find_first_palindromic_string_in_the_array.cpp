class Solution {

	bool isPalindrome(string s){
		int n =s.size();
		for(int i=0,j=n-1;i<j;i++,j--){
			if(s[i]!=s[j]) return false;
		}
		return true;
	}

public:
    string firstPalindrome(vector<string>& words) {
		for(const auto&w:words){
			if(isPalindrome(w)) return w;
		}
		return "";
    }
};
