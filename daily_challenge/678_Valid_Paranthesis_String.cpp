class Solution {
public:
    bool checkValidString(string s) {
		stack<char> s1;
		stack<char> s2;
		for(const auto&c:s){
			if(c==')'){
				while(!s1.empty() && s1.top()!='('){
					s2.push(s1.top());
					s1.pop();
				}
				if(s1.empty()){
					if(s2.empty()) return false;
					s2.pop();
				}
				else{
					s1.pop();
				}
				while(!s2.empty()){
					s1.push(s2.top());
					s2.pop();
				}
			}
			else{
				s1.push(c);
			}
		}
		//check if * can be matched with '('
		while(!s1.empty()){
			if(s1.top() == '('){
				if(s2.empty()) return false;
				s2.pop();
			}
			else{
				s2.push(s1.top());
			}
			s1.pop();
		}
		return true;
    }
};
