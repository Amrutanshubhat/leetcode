class Solution{
	public:
	int mostBooked (int n, vector<vector<int>>& meetings) {
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> occ;
		priority_queue<int,vector<int>,greater<int>> fr;
		sort(meetings.begin(),meetings.end());
		vector<int> cnt(n);

		int tot = meetings.size();	

		for(int i=0;i<n;i++){
			fr.push(i);
		}

		for(int i=0;i<tot;i++){
			//cout<<meetings[i][0]<<" "<<meetings[i][1]<<endl;
			ll et = meetings[i][1], st = meetings[i][0];
			ll dur = et-st;
				
			
			while(!occ.empty() && st >=occ.top().first){
				fr.push(occ.top().second);
				occ.pop();
			}

			int r;
			if(!fr.empty()){
				r = fr.top();
				occ.push({et,r});
				fr.pop();
			} else {
				auto x = occ.top();
				r = x.second;
				occ.pop();
				occ.push({x.first+dur,r});
			}
			//cout<<fr.top()<<"\n";
			cnt[r]++;
		}

		int rm=0,mx=cnt[0];
		for(int i=1;i<n;i++){
			if(cnt[i]>mx){
				mx = cnt[i];
				rm = i;
			}
			//cout<<i<<" "<<cnt[i]<<endl;
		}
		return rm;
    }

};
