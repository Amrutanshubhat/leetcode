class Solution{
	
	public:
		vector<int> solve(int l,int h){
			vector<int> out;
			int x;

			for (int i=1;i<10;i++){
				
				if (i>=l && i<=h) out.push_back(i);
				
				string s = to_string(i);
				
				for(int j=i+1;j<10;j++){
					s+=to_string(j);
					x = stoi(s);
					if(x>=l && x<=h) out.push_back(x);
					else if(x>h) break;
				}
			}
			sort(out.begin(),out.end());
			return out;
		}

};
