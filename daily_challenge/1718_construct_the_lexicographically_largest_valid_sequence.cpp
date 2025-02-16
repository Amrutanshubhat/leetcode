class Solution {
	vector<int> ht;
	vector<bool> visit;
public:
    vector<int> constructDistancedSequence(int n)
	{
        ht.resize(n*2-1);
		visit.resize(n+1);
        backtrack(0, n);
        return ht;
    }
private:
    bool backtrack(int cur, int n)
	{
        if (cur == ht.size())
            return true;

        if (ht[cur] != 0)
            return backtrack(cur+1, n);

        for (int i=n; i > 0; i--) {
            if (visit[i]) continue;
            visit[i] = true;
            ht[cur] = i;

            if (i == 1) {
                if (backtrack(cur+1, n))
                    return true;

			} else if (cur+i < ht.size() && ht[cur+i] == 0) {
                ht[cur+i] = i;

                if (backtrack( cur+1, n))
                    return true;

                ht[cur+i] = 0;
            }

            ht[cur] = 0;
            visit[i] = false;
        }
        return false;
    }
};
