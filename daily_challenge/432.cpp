class AllOne {
	static const int ALPHABET_SIZE = 26;
	typedef struct Trie{
		int cnt;
		struct Trie* next[ALPHABET_SIZE];
	}Trie;
	Trie* trie;
	string mxk, mnk;
	int mxv, mnv;
	int updates, max_counter, min_counter;
public:
    AllOne():
	mxk{}, mnk{}, mxv{}, mnv{}, updates{}, max_counter{}, min_counter{}
	{
		this->trie = (Trie*) calloc(sizeof(*trie), 1);
    }
    
    void inc(string key) {
		Trie* p = this->trie;
		for (const auto&c: key) {
			int index = c-'a';
			if (!p->next[index]) {
				p->next[index] = (Trie*) calloc(sizeof(*trie), 1);
			}
			p = p->next[index];
		}
		p->cnt++;
		updates++;
    }
    
    void dec(string key) {
		Trie* p = this->trie;
		for (const auto&c: key) {
			p = p->next[c-'a'];
		}
		p->cnt--;
		updates++;
    }
    
    string getMaxKey() {
		check_max();
		return mxk;
    }
    
    string getMinKey() {
		check_min();
		return mnk;
    }

private:
	void check_max() {
		if (updates != max_counter) {
			string x = "";
			mxk = "";
			mxv = 0;
			get_max(trie, x);
			max_counter = updates;
		}

	}
	void check_min() {
		if (updates != min_counter) {
			string x = "";
			mnk = "";
			mnv = INT_MAX;
			get_min(trie, x);
			min_counter = updates;
		}
	}
	void get_max(const Trie* p, string& s) {
		if (p->cnt > 0 && p->cnt > mxv) {
			mxk = s;
			mxv = p->cnt;
		}
		for (int i=0; i<ALPHABET_SIZE; i++) {
			if (!p->next[i]) continue;
			s += (char)('a'+i);
			get_max(p->next[i], s);
			s.pop_back();
		}
	}

	void get_min(const Trie* p, string& s) {
		if (p->cnt > 0 && p->cnt < mnv) {
			mnk = s;
			mnv = p->cnt;
		}
		for (int i=0; i<ALPHABET_SIZE; i++) {
			if (!p->next[i]) continue;
			s += (char)('a'+i);
			get_min(p->next[i], s);
			s.pop_back();
		}
	}
};
