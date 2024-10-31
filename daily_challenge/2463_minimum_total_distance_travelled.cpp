class Solution {
/*
// First solution
class Solution {
	vector<int>* r;
	vector<vector<int>>* f;
	vector<vector<vector<ssize_t>>> dp;
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
   		sort(robot.begin(), robot.end());
		sort(factory.begin(), factory.end(), 
				[](const vector<int>&x, const vector<int>& y)->bool {
				return x[0] < y[0];
				});
		r = &robot; f=&factory;
		dp.resize(r->size(), 
				vector<vector<ssize_t>>(f->size(), 
					vector<ssize_t>(r->size(), -1)));
		//ith robot jth factory that processed k robots
		return get_min(0, 0, 0);
    }
private:
	 * if ith robot skips jth factory, i+1th robot can never produce
	 * optimal o/p by visiting jth factory.
	 * Therefore, only forward recursion
	size_t get_min(int i, int j, int k) {
		if (i == r->size()) return 0;
		if (j == f->size()) return LONG_MAX;
		if (dp[i][j][k] != -1) return dp[i][j][k];

		size_t d1=LONG_MAX, d2=LONG_MAX;

		if ((*f)[j][1] > k) {
			d1 = get_min(i+1, j, k+1);
			// to avoid overflow
			d1 = d1 == LONG_MAX ? d1 : d1+abs((*r)[i]-(*f)[j][0]);
		}
		d2 = get_min(i, j+1, 0);
		return dp[i][j][k] = min(d1, d2);
	}
};

*/
public:
  long long minimumTotalDistance(vector<int> &robot,
                                 vector<vector<int>> &factory) {
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end(),
         [](const vector<int> &x, const vector<int> &y) -> bool {
           return x[0] < y[0];
         });
    size_t r = robot.size(), f = factory.size();
    size_t dp[r + 1];
    for (size_t i = 1; i <= r; i++) {
      dp[i] = LONG_MAX;
    }
    dp[0] = 0;
    for (size_t i = 0; i < f; i++) {
      for (size_t c = 0; c < factory[i][1]; c++) {
        for (ssize_t j = r - 1; j >= 0; j--) {
          if (dp[j] != LONG_MAX)
            dp[j + 1] = min(dp[j + 1], dp[j] + abs(robot[j] - factory[i][0]));
        }
      }
    }
    return dp[r];
  }
};
