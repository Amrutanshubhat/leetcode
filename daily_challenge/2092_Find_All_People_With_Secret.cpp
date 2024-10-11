class Solution {
	unordered_map<int,vector<pair<int,int>>> m;
	vector<int> arr;

	void fill_map(vector<vector<int>>& meetings, int firstP){
		m[0].push_back({firstP,0});
		m[firstP].push_back({0,0});
		for(const auto& i:meetings){
			m[i[0]].push_back({i[1],i[2]});
			m[i[1]].push_back({i[0],i[2]});
		}
	}

	void dfs(int val,int time){
		if(arr[val]<=time) return;
		arr[val] = time;
		for(auto& i:m[val]){
			if(i.second>=arr[val])
				dfs(i.first,i.second);
		}
	}

public:
    /*
	struct comp{
		public:
			bool operator()(vector<int> x, vector<int> y){
				return x[2]<y[2];
			}
	}comp;
	*/
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		arr.resize(n,INT_MAX);
		//arr[0] = 0;arr[firstPerson] = 0; //receives secret at time 0
		fill_map(meetings,firstPerson);
		dfs(0,0);
		//sort(meetings.begin(),meetings.end(),comp);
    	/*
		for(const auto& m:meetings){
			//if anyone knows the secrete before the meeting time
			if(arr[m[0]]<=m[2] || arr[m[1]]<=m[2]){
				arr[m[0]] = min(arr[m[0]], m[2]);
				arr[m[1]] = min(arr[m[1]], m[2]);
			}
		}
		*/
		vector<int> out;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<endl;
			if(arr[i]<INT_MAX){
				out.push_back(i);
			}
		}
		return out;

	}
};
