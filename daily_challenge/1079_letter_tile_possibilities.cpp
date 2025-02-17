class Solution {
public:
    int numTilePossibilities(string tiles) {
		const int n = tiles.size();
		set<string> s;
		// store all subsets
		for (int i=1; i<1<<n; i++) {
			string temp;
			for (int j=0; j<n; j++) {
				if ((i>>j)&1) {
					temp += tiles[j];
				}
			}
			sort(temp.begin(), temp.end());
			s.emplace(std::move(temp));
		}
		constexpr int ALPHA = 26;
		auto perm = [this, ALPHA](const string& s) -> int {
			int arr[ALPHA] = {0};
			for (const auto&c: s) {
				arr[c-'A']++;
			}
			int common = 1;
			for (int i=0; i<ALPHA; i++) {
				if (arr[i]) common *= fact(arr[i]);
			}
			return fact(s.size())/common;
		};
		int out=0;
		// permutation of subset elements
		for (const auto& val: s) {
			out += perm(val);
		}
		return out;
    }
private:
	int fact(int n) {
		static int mem[8] = {0}; //testcase limit
		if (mem[n]) return mem[n];
		if (n < 2) return 1;
		return mem[n] = n*fact(n-1);
	}

};
