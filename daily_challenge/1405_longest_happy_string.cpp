class Solution {
	void bubble_sort(vector<pair<int, char>>& v) {
		for (size_t i=0; i<3; i++) {
			for (size_t j=i+1; j<3; j++) {
				if (v[j].first > v[i].first) {
					auto temp = v[j];
					v[j] = v[i];
					v[i] = temp;
				}
			}
		}
	}
public:
    string longestDiverseString(int a, int b, int c) {
    	string out;    
		vector<pair<int, char>> v {
			{a, 'a'}, {b, 'b'}, {c, 'c'}
		};
		bubble_sort(v);
		while (v[0].first) {
			size_t limit = 2;
			if (!out.empty() && (out.back() == v[0].second)) {
				limit = 1;
			}
			for (size_t i=0; i<limit && v[0].first; i++, v[0].first--)
				out.push_back(v[0].second);
			if (!v[1].first) break;
			out.push_back(v[1].second);
			v[1].first--;
			bubble_sort(v);
		}
		return out;
    }
};
