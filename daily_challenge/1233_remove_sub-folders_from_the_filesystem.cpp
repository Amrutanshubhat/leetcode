class Solution {
	unordered_set<string> us;
public:
    vector<string> removeSubfolders(vector<string>& folder) {
    	sort(folder.begin(), folder.end(), 
				[](string& x, string& y)->bool{
					return x.size() < y.size();
				});
		vector<string> out;
		for (const auto&f: folder) {
			if (!is_found(f)) {
				out.push_back(f);
			}
		}
		return out;
    }
private:
	bool is_found(const string& s) {
		string sub;
		for (size_t i=0; i<s.size(); i = sub.size()) {
			sub.append(s.substr(i, s.find_first_of('/', i+1)-i));
			if (us.find(sub) != us.end()) {
				return true;
			}
		}
		us.emplace(std::move(sub));
		return false;
	}
};
