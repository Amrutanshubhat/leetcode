class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
		sort(deck.begin(), deck.end());
		int n = deck.size();
		vector<int> out(n);
		queue<int> q;
		for(int i=0; i<n; i++){
			q.push(i);
		}
		int iter = 0;
		while(!q.empty()){
			out[q.front()] = deck[iter++];
			q.pop();
			if(q.empty()) break;
			q.push(q.front());
			q.pop();
		}
		return out;
    }
};
