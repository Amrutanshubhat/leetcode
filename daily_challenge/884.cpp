class Solution {
	unordered_map<string, int> cnt;
	void get_words(string&& s) {
		stringstream ss{s};
		string token;
		while(ss>>token) cnt[token]++;
	}
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
		get_words(std::move(s1));
		get_words(std::move(s2));
		vector<string> out;
		for (const auto&[s, c]: cnt) {
			if (c==1) out.push_back(s);
		}
		return out;
    }
};
