class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int length = 0;
        map<char,int> table;
        //calculate available chars to make a word
        for(const auto&c:chars) table[c]++;
        for(const auto&s:words){
            map<char,int> t=table;
            bool is_word = true;
            for(const auto&c:s){
                //if enough char is not available, word is no good.
                if(--t[c]<0){
                    is_word=false;
                    break;
                }
            }
            if(is_word) length+=s.length();
        }
        return length;
    }
};
