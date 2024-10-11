class Solution{
	bool is_operand(string& s){
		if (s=="+" || s=="-" || s=="*" || s=="/")
				return true;
		return false;
	}
	public:
		int evalRPN(vector<string>& tokens) {
			int n = tokens.size();
			stack<int> s;
			for(int i=0;i<n;i++){
				//cout<<tokens[i]<<" -> ";
				if (!is_operand(tokens[i])){
					s.push(stoi(tokens[i]));
				}
				else{
					int op2 = s.top(); s.pop();
					int op1 = s.top(); s.pop();
					int op;	

					if(tokens[i] == "+")
						op = op1+op2;

					else if(tokens[i] == "-")
						op = (op1-op2);

					else if(tokens[i] == "*")	
						op = (op1*op2);

					else
						op = (op1/op2);

					s.push(op);
				}
				//cout<<op<<endl;
			}
			return s.top();
    	}
};
