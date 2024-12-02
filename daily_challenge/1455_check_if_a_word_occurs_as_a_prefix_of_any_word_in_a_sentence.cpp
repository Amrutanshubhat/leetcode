class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
    	for (size_t i=0, word_cnt=1; i<sentence.size();i++, word_cnt++) {
			size_t j=0;
			while (j<searchWord.size() && sentence[i] == searchWord[j]) {
				i++; j++;
			}
			if (j == searchWord.size()) return word_cnt;
			while (i<sentence.size() && sentence[i] != ' ') i++;
		} 
		return -1;
    }
};
