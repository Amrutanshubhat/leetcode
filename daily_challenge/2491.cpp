class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
		int n = skill.size();
		int teams = n/2;
		long tot = accumulate(skill.begin(), skill.end(), 0);
		if (tot%teams) return -1;
		int exp = tot/teams;
		sort(skill.begin(), skill.end());
		long long out = 0;
		for (int i=0; i<teams; i++) {
			if (skill[i]+skill[n-i-1] != exp) return -1;
			out += skill[i]*skill[n-i-1];
		}
		return out;
    }
};
