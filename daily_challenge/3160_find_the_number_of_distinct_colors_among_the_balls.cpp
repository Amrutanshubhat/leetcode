class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       	const int n = queries.size();
		
		unordered_map<int, int> b, c;
		vector<int> out;

		int colors = 0;
		for (const auto&query: queries) {
			int old_col=-1, new_col = query[1];
			auto it = b.find(query[0]);

			if (it == b.end()) {
				b.insert({ query[0], new_col });
				c[new_col]++;
				if (c[new_col] == 1) 
					colors++;

			} else if (it->second != new_col) {
				old_col = it->second;
				c[old_col]--;
				it->second = new_col;
				c[new_col]++;
				if (c[new_col] == 1) 
					colors++;
			}

			if (old_col != -1 && c[old_col]==0)
				colors--;

			out.push_back(colors);
		}
		return out;
    }
};
