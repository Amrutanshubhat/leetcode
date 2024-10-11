class Solution {
	bool isDigit(char c) {
		if (c - '0' < 10 && c-'0' >= 0) return true;
		return false;
	}
	bool isSmall(char c) {
		if (c-'a' < 26 && c-'a' >= 0) {
			return true;
		}
		return false;
	}
public:
    string countOfAtoms(string formula) {
		vector<pair<string, int>> v;
		int n = formula.size();

		string s;
		for (int i=0; i<n; i++) {
			if (!s.empty() && !isSmall(formula[i])) {
				v.push_back({s, 1});
				s = "";
			}

			string temp{formula[i]};
			if (formula[i] == ')' || formula[i] == '(') {
				v.push_back({temp, 1});
			} else if (isDigit(formula[i])) {
				while (isDigit(formula[i+1])){
					temp += formula[i+1];
					i++;
				}
				v.back().second = stoi(temp);
			} else {
				s += temp;
			}
		}
		if (!s.empty()) v.push_back({s, 1});

		// TODO: implement stack to resolve paranthesis
		// implement hashmap to finalize the count
		stack<pair<string,int>> st;
		for (const auto& elem: v) {
			if (elem.first == ")") {
				int cnt = elem.second;
				stack<pair<string, int>> temp;
				while (st.top().first != "(") {
					temp.push(st.top());
					st.pop();
					temp.top().second *= cnt;
				}
				st.pop();
				while (!temp.empty()) {
					st.push(temp.top());
					temp.pop();
				}
			} else {
				st.push(elem);
			}
		}
		map<string, int> m;
		while (!st.empty()) {
			m[st.top().first] += st.top().second;
			st.pop();
		}
		string out;
		for(const auto& [elem, cnt]: m) {
			if (cnt > 1)
				out += elem+to_string(cnt);
			else out += elem;
		}
		return out;
    }
};
