class Solution {
	struct comp {
		bool operator() (int x, int y) {
			return x>y;
		}
	} comp;
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), comp);
		long long out = 0;
		for (int i=0; i<happiness.size(); i++) {
			int h = happiness[i] - i;
			if (h<0 || i==k) break;
			out += h;
		}
		return out;
    }
};
