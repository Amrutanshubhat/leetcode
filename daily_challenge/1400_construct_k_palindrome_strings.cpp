class Solution {
public:
    bool canConstruct(string s, int k) {
       	constexpr int alpha_size=26;
		int ht[alpha_size] = {0};

		for (const auto&c: s)
			ht[c-'a']++;

		int odd=0;
		for (int i=0; i<alpha_size; i++) {
			if (ht[i]&1) odd++;
		}
		return ((s.size() < k) || (odd > k))? false : true;
    }
};
