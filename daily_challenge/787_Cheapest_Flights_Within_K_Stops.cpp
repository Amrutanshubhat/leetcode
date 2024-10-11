class Solution {

	unordered_map<int,vector<pair<int,int>>> adj;

	void fill_adj(vector<vector<int>>& flights){
		for(const auto& f:flights){
			this->adj[f[0]].push_back({f[1],f[2]});
		}
	}
	int bfs(int src,int dst, int k, int n){
		queue<pair<int,int>> q;
		q.push({src,0});
		q.push({-1,-1});
		int dist = 0;
		int out=INT_MAX;
		vector<int> processed(n,INT_MAX);
		while(!q.empty()){
			pair<int,int> temp = q.front(); q.pop();
			if(temp.first==-1 && temp.second==-1){
				if(!q.empty()){
					q.push(temp);
				}
				dist++;
				if(dist>k) break;
			}
			else{
				for(auto& p:adj[temp.first]){
					if(p.first == dst){
						out = min(out, temp.second+p.second);
						continue;
					}
					//if visited node cost is more than current path process(traverse) again.
					if(temp.second+p.second < processed[p.first]){
						processed[p.first] = temp.second+p.second;
						q.push({p.first,processed[p.first]});
					}
				}
			}

		}
		if(out == INT_MAX) return -1;
		return out;
	}

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        fill_adj(flights);
		return bfs(src,dst,k, n);
	} 
};
