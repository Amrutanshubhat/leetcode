class Solution {
public:
    int minimumLength(string s) {
    	constexpr int alpha_size=26;
		int ht[alpha_size]={0};
		
		for (const auto&c: s) {
			if (ht[c-'a'] == 2) ht[c-'a'] = 1;
			else ht[c-'a']++;
		}

		int cnt=0;
		for (int i=0; i<alpha_size; i++)
			cnt += ht[i];

		return cnt;
    }
};
