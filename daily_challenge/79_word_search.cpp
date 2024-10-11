class Solution {
	bool exhaustive_search(vector<vector<char>>& board, int x, int y, int p, string& word){
		if(x>=board.size() || y>=board[0].size() || x<0 || y<0 || board[x][y]=='$'){
			return false;	
		}
		if(board[x][y] != word[p]) return false;
		if(p == word.size()-1) return true;
		const char val = board[x][y];
		board[x][y] = '$';
		bool found = exhaustive_search(board, x+1, y, p+1, word) || 
			exhaustive_search(board, x, y+1, p+1, word) || 
			exhaustive_search(board, x, y-1, p+1, word) || 
			exhaustive_search(board, x-1, y, p+1, word);
		board[x][y] = val;
		return found;
	}
public:
    bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(exhaustive_search(board, i, j, 0, word))
					return true;
			}
		}
  		return false;      
    }
};
