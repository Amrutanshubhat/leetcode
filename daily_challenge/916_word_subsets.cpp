class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
		constexpr int alpha_size=26;
       	int n=words1.size();
		vector<vector<int>> ht(n, vector<int>(alpha_size));

		for (int i=0; i<n; i++)
			for (int j=0; j<words1[i].size(); j++)
				ht[i][words1[i][j]-'a']++;

		vector<string> out;

		int cnt[alpha_size]={0};
		for (const auto& word: words2) {
			int temp_cnt[alpha_size]={0};

			for (int i=0; i<word.size(); i++)
				temp_cnt[word[i]-'a']++;

			for (int i=0; i<alpha_size; i++) {
				if (cnt[i]<temp_cnt[i])
					cnt[i] = temp_cnt[i];
			}
		}


		for (int i=0; i<n; i++) {
			int j=0;
			for (; j<alpha_size; j++)
				if (ht[i][j] < cnt[j])
					break;
			if (j==alpha_size) {
				out.push_back(std::move(words1[i]));
			}
		}

		return out;
    }
};
