class Solution {
	struct Trie {
		int cnt;
		struct Trie* next[26];
		Trie(): cnt{0} {
			for (int i=0; i<26; i++) {
				this->next[i] = NULL;
			}
		}
		void insert(const string& s) {
			Trie* p = this;
			for (const auto&c: s){
				int index = c-'a';
				if (p->next[index] == nullptr) {
					p->next[index] = new struct Trie();
				}
				p = p->next[index];
				p->cnt++;
			}
		}
		int find(const string& s) {
			struct Trie* p = this;
			int cnt = 0;
			for (const auto&c: s) {
				int index = c-'a';
				if (!p->next[index]) {
					break;
				}
				p = p->next[index];
				cnt += p->cnt;
			}
			return cnt;
		}
	};
	struct Trie* trie {new struct Trie};
	vector<int> out;
public:
    vector<int> sumPrefixScores(vector<string>& words) {
		int n = words.size();
		out.resize(n);
		for (const auto&word: words) {
			trie->insert(word);
		}
		for (int i=0; i<n; i++) {
			out[i] = trie->find(words[i]);
		}
		return out;
    }
};
