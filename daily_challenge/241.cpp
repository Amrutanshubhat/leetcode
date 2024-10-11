class Solution {
	unordered_map<string, vector<int>> hash;
public:
    vector<int> diffWaysToCompute(string expression) {
		return ways(std::move(expression));		        
    }

private:
	vector<int> ways(string&& s) {
		if (hash.find(s) != hash.end()) {
			return hash[s];
		}
		vector<int> out;
		for (size_t i=0; i<s.size(); i++) {
			if (!ispunct(s[i])) continue;

			for (const int a: ways(s.substr(0, i))) {
				for (const int b: ways(s.substr(i+1))) {
					switch(s[i]) {
						case '+': out.push_back(a+b); break;
						case '-': out.push_back(a-b); break;
						case '*': out.push_back(a*b); break;
					}
				}
			}
		}

		return hash[s] = out.empty() ? vector<int>{stoi(s)} : out;
	}
};
