class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		int n = heights.size();
		priority_queue<int,vector<int>,greater<int>> q;
		int hdiff;
		for(int i=1;i<n;i++){
			hdiff = heights[i]-heights[i-1];
			if(hdiff>0){
				if(ladders>0){
					q.push(hdiff);
					ladders--;
				}
				else{
					if (q.empty() || hdiff <= q.top()){
						bricks-=hdiff;
					} else {
						bricks-=q.top();q.pop();
						q.push(hdiff);
					}
					if(bricks<0) return i-1;
				}
			}	
		}
		return n-1;
    }
};
