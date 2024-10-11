class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
		int out = 0, depth = 0;
		for(const auto&c:s){
			if(c=='('){
				st.push(c);
				depth++;
				if(depth>out) out = depth;
			}
			else if(c==')'){
				depth--;
				if(st.empty()) return 0;
				st.pop();
			}
		}
		if(!st.empty()) return 0;
		return out;
    }
};
