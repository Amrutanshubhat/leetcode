class Solution {
public:
    bool isCircularSentence(string sentence) {
		if (sentence.front() != sentence.back()) return false;
		for (size_t i=0; i<sentence.size(); i++) {
			if (sentence[i] == ' ')	 {
				if (sentence[i-1] != sentence[i+1]) return false;
			}
		}
		return true;
    }
};
