class Solution{
	
	public:
		int bagOfTokensScore(vector<int>& tokens, int power) {
			int n = tokens.size();
			if(n==0) return 0;
        	int score = 0;
			sort(tokens.begin(),tokens.end());
			int x = 0, y = n-1;
			while(x<y){
				if(tokens[x]<=power){
					power-=tokens[x];
					score++;
					x++;
				}
				//no score no face-down
				else if(score>0){
					power+=tokens[y];
					score--;
					y--;
				}
				//no progress can be made
				else{
					break;
				}
			}
			//x==y
			if(tokens[x]<=power) score++;
			return score;
		}
};
