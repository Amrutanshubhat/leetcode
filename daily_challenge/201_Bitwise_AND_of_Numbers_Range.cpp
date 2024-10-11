class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
		int shift = 0;
		while(left>0 && left!=right){
			left>>=1;
			right>>=1;
			shift++;
		}
		return left<<shift;
		/*
		//Solution 2:
		int out=0;
		string l="",r="";
		while(left>0){
			l += to_string(left%2);
			left/=2;
		}
		while(right>0){
			r += to_string(right%2);
			right/=2;
		}
		int n = l.size();
		if(r.size()>n) return 0;
		for(int i=n-1;i>=0;i--){
			if(l[i]==r[i]){
				if(l[i]=='1' && r[i]=='1') out+=pow(2,i);
			}
			else break;
		}
		return out;
		*/
    }
};
