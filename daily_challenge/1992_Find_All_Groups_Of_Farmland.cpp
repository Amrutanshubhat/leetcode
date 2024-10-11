class Solution {
	pair<int,int> dfs(vector<vector<int>>& land, int i, int j, vector<vector<bool>>& v){
		int r = land.size();
		int c = land[0].size();
		v[i][j] = true;
		pair<int,int> out1 = {i, j}, out2 = {i, j};
		if (i+1 < r && land[i+1][j] && !v[i+1][j]){
			out1 = dfs(land, i+1, j, v);
		}
		if (j+1 < c && land[i][j+1] && !v[i][j+1]){
			out2 = dfs(land, i, j+1, v);
		}
		return {max(out1.first, out2.first),max(out1.second, out2.second)};
	}
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		int r = land.size();
		int c = land[0].size();
		vector<vector<bool>> v(r, vector<bool>(c));
		vector<vector<int>> out;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if (land[i][j] && !v[i][j]){
					vector<int> cord(4);
					pair<int,int> end_cord = dfs(land, i, j, v);
					cord = {i, j, end_cord.first, end_cord.second};
					out.push_back(cord);
				}
			}
		}
		return out;
    }
};
