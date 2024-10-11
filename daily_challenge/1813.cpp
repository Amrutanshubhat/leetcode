class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
		vector<string> v1, v2;
		string *s1, *s2;
		if (sentence1.size() > sentence2.size()) {
			s1 = &sentence1;
			s2 = &sentence2;

		} else {
			s1 = &sentence2;
			s2 = &sentence1;
		}
		vector<string>* v = &v1;
		string *s = s1;
		for (size_t i=0; i<2; i++) {
			ssize_t nxt = 0, cur = 0;
			while (nxt != s->npos) {
				nxt = s->find_first_of(' ', cur);
				v->emplace_back(s->substr(cur, nxt-cur));
				cur = nxt+1;
			}
			s = s2;
			v = &v2;
		}
		

		size_t af=0, al = v1.size()-1;
		size_t bf = 0, bl = v2.size()-1;
		while(bf < bl && v1[af] == v2[bf]) {af++; bf++;}
		while (bf < bl && v1[al] == v2[bl]) {al--; bl--;}
		if (bf == bl) {
			if (v1[af] == v2[bf] || v1[al] == v2[bl]) return true;
			return false;
		}
		return false;
    }
};
