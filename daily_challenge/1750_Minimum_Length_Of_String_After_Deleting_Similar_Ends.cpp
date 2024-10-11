class Solution{
	
	public:
	int minimumLength(string s) {
		int n = s.size();
		int x = 0, y = n-1;
		while(x<y){
			if(s[x]!=s[y]) break;
			while(x<y && s[x]==s[x+1]) x++;
			while(y>x && s[y] == s[y-1]) y--;
			x++;
			y--;
		}
		if(x>y) return 0;
    	return (y-x)+1;    
    }

};
