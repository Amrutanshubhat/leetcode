class Solution {
public:
    string minRemoveToMakeValid(string s) {
		stack<int> st;
		string out = "";
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				st.push(out.size());
				out+=s[i];
			}
			else if(s[i]==')' && !st.empty()){
				//found matching paranthesis
				st.pop();
				out+=s[i];
			}
			else if(s[i]!=')'){
				out+=s[i];
			}
		}
		//remove redundant open paranthesis
		while(!st.empty()){
			out.erase(st.top(), 1);
			st.pop();
		}
		return out;
    }
};
