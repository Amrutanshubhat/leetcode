class Solution {
public:

	bool is_equal(int* a,int* b){
		for(int i=0;i<58;i++){
			if(b[i]>0 && a[i]<b[i]) return false;
		}
		return true;
	}

    string minWindow(string s, string t) {
        int a[58] = {0},b[58]={0}, c[58] = {0};
		int n = s.size();
		string out;
		for(const auto& i:s){
			a[i-'A']++;
		}
		
		for(const auto& i:t){
			b[i-'A']++;
		}

		int p1 = 0, p2 = 0;
		while(p2<n){
			c[s[p2]-'A']++;
			if(is_equal(c,b)) break;
			p2++;
		}
		if(! is_equal(c,b)) return "";
		out = s.substr(p1,(p2-p1+1));
		while(p2<n){
			while(p1<=p2){
				c[s[p1]-'A']--;
				if(! is_equal(c,b)){
					c[s[p1]-'A']++;
					break;
				}
				p1++;
			}

			//cout<<p1<<" "<<p2<<endl;

			if(out.size() > (p2-p1+1)){
				out = s.substr(p1,(p2-p1+1));
			}
			if(++p2 < n) c[s[p2]-'A']++;
		}
		//cout<<p1<<" "<<p2<<endl;
		return out; 
    }
};
